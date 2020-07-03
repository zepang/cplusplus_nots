#include <iostream>

extern const int num;

int main()
{
  const int *ptr;
  int val = 3;
  ptr = &val; //ok
  int *ptr1 = &val;
  *ptr1=4;
  std::cout << num << std::endl;
  std::cout << *ptr << std::endl;
}

