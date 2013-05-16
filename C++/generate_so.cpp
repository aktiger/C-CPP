/*
This file is used to generate so file, when compile, use the following command:
g++ -fpic -shared -o generate_so
 */
extern "C"
{
int my_add_so(float x, int y)
{
  return x+y;
}
}

