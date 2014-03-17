#include <iostream>
#include <pthread.h>
#include <boost/lexical_cast.hpp>


pthread_mutex_t mutex_is_tag = PTHREAD_MUTEX_INITIALIZER;
static int is_tag = 0;

void *fun1(void * param) {
  int flag = 0;
  try {
    flag = boost::lexical_cast<int>(reinterpret_cast<char *>(param));
    // std::cout << "flag is " << flag << std::endl;
  } catch (boost::bad_lexical_cast) {
    std::cout << "boost::lexical_cast error " << std::endl;
  }
  switch(flag) {
    case 1:   std::cout << "in fun1 " << " " << reinterpret_cast<char *>(param) <<  " pthread_self is :" << pthread_self() << std::endl;
              pthread_mutex_lock(&mutex_is_tag);
              is_tag = 11;
              sleep(1);
              pthread_mutex_unlock(&mutex_is_tag);
              break;
    case 2:   std::cout << "in fun2 " << " " << reinterpret_cast<char *>(param) <<  " pthread_self is :" << pthread_self() << std::endl;
              pthread_mutex_lock(&mutex_is_tag);
              is_tag = 22;
              pthread_mutex_unlock(&mutex_is_tag);
              break;
    case 3:   std::cout << "in fun3 " << " " << reinterpret_cast<char *>(param) <<  " pthread_self is :" << pthread_self() << std::endl;
              pthread_mutex_lock(&mutex_is_tag);      
              break;
    default:
      std::cout << "in default" << std::endl;
  }
}


int main() {
  pthread_t pid1;
  pthread_t pid2;
  pthread_create(&pid1, NULL, fun1, const_cast<char *>("1"));
  pthread_create(&pid2, NULL, fun1, const_cast<char *>("2"));

  pthread_detach(pid1);
  pthread_detach(pid2);
  std::cout << static_cast<intmax_t>(3) << std::endl;
  sleep(5);
  pthread_mutex_lock(&mutex_is_tag);
  std::cout << "is_tag is " << is_tag << std::endl;
  pthread_mutex_unlock(&mutex_is_tag);

  std::cout << "pthread equal " << pthread_equal(pid1, pid2) << std::endl;

  return 0;

}
