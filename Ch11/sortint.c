// sortint.c
#include <stdio.h>
#include <stdlib.h>
int comparefunc(const void * arg1, const void * arg2)
{
  const int * ptr1 = (const int *) arg1; // cast type
  const int * ptr2 = (const int *) arg2;  
  const int val1 = * ptr1; // get the value from the address
  const int val2 = * ptr2;
  if (val1 < val2) // compare the value
    { return -1; }
  if (val1 == val2)
    { return 0; }
  return 1;
}
int main(int argc, char * argv[])
{
  // need two file names: input and output
  if (argc < 3)
    {
      return EXIT_FAILURE;
    }
  // open the input file
  FILE * infptr;
  infptr = fopen(argv[1], "r");
  if (infptr == NULL)
    {
      return EXIT_FAILURE;
    }
  // count the number of integers in the file
  int count = 0;
  int val;
  while (fscanf(infptr, "%d", & val) == 1)
    {
      count ++;
    }
  // allocate memory for the array
  int * arr;
  arr = malloc(sizeof(int) * count);
  if (arr == NULL)
    {
      fclose (infptr);
      return EXIT_FAILURE;
    }
  // go to the beginning of the file
  fseek(infptr, 0, SEEK_SET);
  // read the file again and fill the array
  int ind = 0; // array index
  while (fscanf(infptr, "%d", & val) == 1)
    {
      arr[ind] = val;
      ind ++;
    }
  // sort the array
  qsort(& arr[0], count, sizeof(int), comparefunc);
  // close the input file
  fclose (infptr);
  // open the output file
  FILE * outfptr;
  outfptr = fopen(argv[2], "w");
  if (outfptr == NULL)
    {
      free (arr); // do not forget to release memory
      return EXIT_FAILURE;
    }
  // write the sorted array to the output file
  for (ind = 0; ind < count; ind ++)
    {
      fprintf(outfptr, "%d\n", arr[ind]);
    }
  // close outupt file
  fclose (outfptr);
  // release the array's memory
  free (arr);
  return EXIT_SUCCESS;
}
