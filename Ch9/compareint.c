// compareint.c
int comparefunc(const void * arg1, const void * arg2) 
{
  const int * ptr1 = (const int *) arg1; 
  const int * ptr2 = (const int *) arg2;  
  int val1 = * ptr1; 
  int val2 = * ptr2;
  if (val1 < val2)  { return -1; }
  if (val1 == val2) { return 0; }
  return 1;
}
