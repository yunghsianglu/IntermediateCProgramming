// const2.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  char str1[20];
  char str2[20];
  strcpy(str1, "First");
  strcpy(str2, "Second");
  const char * chptr1 = & str1[0];
  char * const chptr2 = & str1[0];
  const char * const chptr3 = & str1[0];
  // * chptr1 = 'C';     // not allowed
  * chptr2 = 'C';        // OK
  chptr1 = & str2[0];    // OK
  // chptr2 = & str2[0]; // not allowed
  // chptr3 = & str2[0]; // not allowed
  // * chptr3 = 'C';     // not allowed
  return EXIT_SUCCESS;
}
