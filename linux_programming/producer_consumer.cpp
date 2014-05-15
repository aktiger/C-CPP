#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE	8

struct Products
{
  int			buffer[BUFFER_SIZE];
  pthread_mutex_t	locker; //��֤��ȡ������ԭ���� ������
  pthread_cond_t	notEmpty;	//�Ƿ�ɶ�
  pthread_cond_t	notFull;	//�Ƿ��д
  int			posReadFrom;
  int			posWriteTo;
};

int BufferIsFull(struct Products* products)
{
  if ((products->posWriteTo + 1) % BUFFER_SIZE == products->posReadFrom)
  {
    return (1);
  }
  return (0);
}

int BufferIsEmpty(struct Products* products)
{
  if (products->posWriteTo == products->posReadFrom)
  {
    return (1);
  }

  return (0);
}

//�����Ʒ��

void Produce(struct Products* products, int item)
{
  pthread_mutex_lock(&products->locker);	//ԭ�Ӳ���

  while (BufferIsFull(products))
  {
    pthread_cond_wait(&products->notFull, &products->locker);
  }				//�޿ռ��д��

  //д������
  products->buffer[products->posWriteTo] = item;
  products->posWriteTo++;

  if (products->posWriteTo >= BUFFER_SIZE)
    products->posWriteTo = 0;

  pthread_cond_signal(&products->notEmpty);	//����
  pthread_mutex_unlock(&products->locker);	//����
}

int Consume(struct Products* products)
{
  int	item;

  pthread_mutex_lock(&products->locker);

  while (BufferIsEmpty(products))
  {
    pthread_cond_wait(&products->notEmpty, &products->locker);
  }				//Ϊ��ʱ�����ȴ�,�����ݿɶ�

  //��ȡ����
  item = products->buffer[products->posReadFrom];
  products->posReadFrom++;

  if (products->posReadFrom >= BUFFER_SIZE)	//�����ĩβ,��ͷ��ȡ
    products->posReadFrom = 0;

  pthread_cond_signal(&products->notFull);
  pthread_mutex_unlock(&products->locker);

  return item;
}


#define END_FLAG	(-1)

struct Products products;

void* ProducerThread(void* data)
{
  int	i;
  for (i = 0; i < 16; ++i)
  {
    printf("producer: %d\n", i);
    Produce(&products, i);
  }
  Produce(&products, END_FLAG);
  return NULL;
}

void* ConsumerThread(void* data)
{
  int	item;

  while (1)
  {
    item = Consume(&products);
    if (END_FLAG == item)
      break;
    printf("consumer: %d\n", item);
  }
  return (NULL);
}

int main(int argc, char* argv[])
{
  pthread_t	producer;
  pthread_t	consumer;
  int		result;

  pthread_create(&producer, NULL, &ProducerThread, NULL);
  pthread_create(&consumer, NULL, &ConsumerThread, NULL);

  pthread_join(producer, (void **)&result);
  pthread_join(consumer, (void **)&result);


  exit(EXIT_SUCCESS);
}
        