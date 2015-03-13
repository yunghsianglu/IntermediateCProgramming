// const.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
  char str1[20];
  char str2[20];
  strcpy(str1, "First");
  strcpy(str2, "Second");
  const char * chptr1 = & str1[0]; // const before char
  char * const chptr2 = & str1[0]; // const after  char
  // * chptr1 = 'C';     // not allowed
  * chptr2 = 'C';        // OK
  chptr1 = & str2[0];    // OK
  // chptr2 = & str2[0]; // not allowed
  return EXIT_SUCCESS;
}
