/*
  Author: Justinzhang
  Email: uestczhangchao@gmail.com
  Time: Mon Sep  2 21:58:08 CST 2013
  Desc: For the purpose of practicing G++ size zero array.
  Link: http://www.delorie.com/gnu/docs/gcc/gcc_42.html 
 */
#include <iostream>

typedef struct im_ts_cs_req_t
{
  int		base;
  int		nlen;
  char		szdata[];
} im_ts_cs_req_t __attribute__((packed));

struct xx
{
  int	y[];
};
char data_send_to_hi[10]={'0','0','0','0','0','0','0','0','0','0'};


int main(int argc, char *argv[])
{
  char char_array[] = {'a','b','c','d'};

  std::cout << typeid(char_array).name() << std::endl;
  std::cout << sizeof(int) << std::endl;
  std::cout << sizeof(xx) << std::endl;

  im_ts_cs_req_t	*im_data = (im_ts_cs_req_t*)malloc(sizeof (*im_data) + sizeof(data_send_to_hi));
  std::cout << typeid(im_data->szdata).name() << std::endl;

  strncpy(im_data->szdata,data_send_to_hi,sizeof(data_send_to_hi));

  std::cout << im_data->szdata << std::endl;

  std::cout << sizeof(im_ts_cs_req_t) << std::endl;
    
  return 0;
}
