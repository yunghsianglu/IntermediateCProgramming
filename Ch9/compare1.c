// comparefunc.c
int comparefunc(const void * arg1, const void * arg2)
{
  // convert void * to a known type (int, char, double ...)
  const type * ptr1 = (const type *) arg1; 
  const type * ptr2 = (const type *) arg2;  
  // get the value from the address
  const type val1 = * ptr1; 
  const type val2 = * ptr2;
  // compare the value
  if (val1 < val2) 
    { return -1; }
  if (val1 == val2)
    { return 0; }
  return 1;
}
