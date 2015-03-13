// arithmetic3.c
#include <stdio.h>
#include <stdlib.h>
int main (int argc ,char * * argv)
{
  int    arr1[] = {7, 2, 5, 3, 1, 6, -8, 16, 4};
  char   arr2[] = {'m', 'q', 'k', 'z', '%', '>'};
  double arr3[] = {3.14, -2.718, 6.626, 0.529};
  int    * iptr = & arr1[3];
  printf("%d\n", * iptr);
  long int addr13 = (long int) iptr;
  iptr --;
  printf("%d\n", * iptr);
  long int addr12 = (long int) iptr;
  printf("addr13 - addr12 = %ld\n", addr13 - addr12);
  printf("=====================================\n");
  
  char   * cptr = & arr2[1];
  printf("%c\n", * cptr);
  long int addr21 = (long int) cptr;
  cptr ++;
  printf("%c\n", * cptr);
  long int addr22 = (long int) cptr;
  printf("addr22 - addr21 = %ld\n", addr22 - addr21);
  printf("=====================================\n");

  double * dptr = & arr3[2];
  printf("%f\n", * dptr);
  long int addr32 = (long int) dptr;
  dptr --;
  printf("%f\n", * dptr);
  long int addr31 = (long int) dptr;
  printf("addr32 - addr31 = %ld\n", addr32 - addr31);
  return EXIT_SUCCESS;
}
