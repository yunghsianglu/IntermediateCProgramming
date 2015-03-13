// swap2.c
#include <stdio.h>
#include <stdlib.h>
void swap2 (int * a , int * b)
{
  int * k = a;
  a = b;
  b = k;
}

int main (int argc ,char * * argv)
{
  int u;
  int t;
  u = 17;
  t = -96;
  printf ("before swap2: u = %d , t = %d \n" , u , t);
  swap2 (& u , & t);
  printf ("after  swap2: u = %d , t = %d \n" , u , t);
  return EXIT_SUCCESS;
}
