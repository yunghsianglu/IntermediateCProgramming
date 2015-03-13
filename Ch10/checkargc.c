/* 
 * checkargc.c
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
  if (argc < 2)
    {
      printf("Need to provide the file's name.\n");
      return EXIT_FAILURE;
    }
  printf("The name of the file is %s.\n", argv[1]);
  return EXIT_SUCCESS;
}
