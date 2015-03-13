// arithmetic2.c
#include <stdio.h>
#include <stdlib.h>
int main (int argc ,char * * argv)
{
  int    arr1[] = {7, 2, 5, 3, 1, 6, -8, 16, 4};
  char   arr2[] = {'m', 'q', 'k', 'z', '%', '>'};
  double arr3[] = {3.14, -2.718, 6.626, 0.529};
  long int addr10 = (long int) (& arr1[0]);
  long int addr11 = (long int) (& arr1[1]);
  long int addr12 = (long int) (& arr1[2]);
  printf("%ld, %ld, %ld\n", addr12, addr11, addr10);
  printf("%ld, %ld\n", addr12 - addr11, addr11 - addr10);
  long int addr20 = (long int) (& arr2[0]);
  long int addr21 = (long int) (& arr2[1]);
  long int addr22 = (long int) (& arr2[2]);
  printf("%ld, %ld, %ld\n", addr22, addr21, addr20);
  printf("%ld, %ld\n", addr22 - addr21, addr21 - addr20);
  long int addr30 = (long int) (& arr3[0]);
  long int addr31 = (long int) (& arr3[1]);
  long int addr32 = (long int) (& arr3[2]);
  printf("%ld, %ld, %ld\n", addr32, addr31, addr30);
  printf("%ld, %ld\n", addr32 - addr31, addr31 - addr30);
  return EXIT_SUCCESS;
}
