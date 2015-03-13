// mainqsortstr.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpstringp(const void *arg1, const void *arg2);
int main(int argc, char * *argv)
{
  int ar;
  if (argc < 2) 
    {
      fprintf(stderr, "Usage: %s <string>...\n", argv[0]);
      return EXIT_FAILURE;
    }
  qsort(&argv[0], argc, sizeof(char *), cmpstringp);
  for (ar = 0; ar < argc; ar++)
    {
      printf("%s\n", argv[ar]);
    }
  return EXIT_SUCCESS;
} 
