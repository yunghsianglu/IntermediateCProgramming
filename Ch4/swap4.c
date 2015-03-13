// swap4.c
#include <stdio.h>
#include <stdlib.h>

void swap4 (int * a, int * b)
{
  int k = * a;
  * a = * b;
  * b = * k;
}


int main (int argc ,char * * argv)
{
  int u;
  int t;
  u = 17;
  t = -96;
  printf ("before swap4: u = %d , t = %d \n" , u , t);
  swap4 (& u , & t);
  printf ("after  swap4: u = %d , t = %d \n" , u , t);
  return EXIT_SUCCESS;
}
