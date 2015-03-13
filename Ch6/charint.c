/*
 * charint.c
 * how C treats integer and character differently
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
  int v = 55;
  printf("%d\n", v);
  printf("%c\n", v);
  return EXIT_SUCCESS;
}
