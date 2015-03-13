/*
 * countsubstr.c
 * count the occurrence of a substring
 * argv[1] is the longer string
 * argv[2] is the shorter string
 * argv[1] may contain space if the string enclosed by " "
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * argv[])
{
  int count = 0;
  char * ptr;
  if (argc < 3)
    {
      printf("Please enter two strings.\n");
      return EXIT_FAILURE;
    }
  printf("argv[1] = %s, strlen = %d\n", argv[1], 
	 (int) strlen(argv[1]));
  printf("argv[2] = %s, strlen = %d\n", argv[2], 
	 (int) strlen(argv[2]));
  ptr = argv[1];
  do
    {
      ptr = strstr(ptr, argv[2]);
      if (ptr != NULL)
	{
	  printf("%s\n", ptr);
	  count ++;
	  ptr ++;
	}
    } while (ptr != NULL);
  if (count == 0)
    {
      printf("argv[2] is not a substring of argv[1].\n");   
    }
  else
    {
      printf("argv[2] occurs %d times in argv[1].\n", count);   
    }
  return EXIT_SUCCESS;
}
