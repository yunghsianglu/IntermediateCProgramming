// structfile.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma pack(1) // tell compiler not to pad any space
typedef struct
{
  int length;
  int * data;
} Array;
// for simplicity, this program does not check errors
int main(int argc, char **argv)
{
  int length = 10;
  char * filename = "data";
  // create an object
  Array * aptr1 = NULL;
  printf("sizeof(aptr1) = %d\n", (int) sizeof(aptr1));
  aptr1 = malloc(sizeof(Array));
  printf("sizeof(aptr1) = %d, sizeof(Array) = %d\n", 
	 (int) sizeof(aptr1), (int) sizeof(Array));
  // allocate memory for the data
  aptr1 -> length = length;
  aptr1 -> data = malloc(sizeof(int) * (aptr1 -> length));
  printf("sizeof(aptr1): %d, sizeof(aptr1 -> data): %d\n", 
	 (int) sizeof(aptr1), (int) sizeof(aptr1 -> data));
  // initialize the values of the array
  int ind;
  for (ind = 0; ind < (aptr1 -> length); ind ++)
    {
      aptr1 -> data[ind] = ind;
    }
  // save the data to a file
  FILE * fptr = fopen(filename, "w");
  // write the data to the file
  if (fwrite(aptr1, sizeof(Array), 1, fptr) != 1)
    {
      // fwrite fail
      return EXIT_FAILURE;
    }
  printf("ftell(fptr) = %d\n", (int) ftell(fptr));
  fclose (fptr);

  // fill the array with random numbers
  // ensure the heap contains garbage before releasing it
  srand(time(NULL)); // set the seed of the random number
  for (ind = 0; ind < (aptr1 -> length); ind ++)
    {
      aptr1 -> data[ind] = rand(); 
    }

  // release memory
  free(aptr1 -> data);
  free(aptr1);
  // read the data from the file
  Array * aptr2 = NULL;
  aptr2 = malloc(sizeof(Array));
  fptr = fopen(filename, "r");
  if (fread(aptr2, sizeof(Array), 1, fptr) != 1)
    {
      // fread fail
      return EXIT_FAILURE;
    }
  // add the data
  int sum = 0;
  for (ind = 0; ind < (aptr2 -> length); ind ++)
    {
      sum += aptr2 -> data[ind];
    }
  printf("sum = %d\n", sum);
  // release memory
  free(aptr2);
  return EXIT_SUCCESS;
}
  
