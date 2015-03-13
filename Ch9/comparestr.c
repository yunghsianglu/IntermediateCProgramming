// comparestr.c
#include <string.h>
int cmpstringp(const void *arg1, const void *arg2)
{
  // ptr1 and ptr2 are string *
  // string is char *, thus ptr1 and ptr2 are char * *
  const char * const * ptr1 = (const char * *) arg1; 
  const char * const * ptr2 = (const char * *) arg2;
  const char * str1 = * ptr1; // type: string
  const char * str2 = * ptr2;
  return strcmp(str1, str2);
}

