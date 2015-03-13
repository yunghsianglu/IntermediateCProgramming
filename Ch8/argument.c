/* argument.c 
 * pass the address of heap memory as a function argument
 */
#include <stdio.h>
#include <stdlib.h>
int sum(int * array, int length)
{
  int iter;
  int answer = 0;
  for (iter = 0; iter < length; iter ++)
    {
      answer += array[iter];
    }
  return answer;
}
int main(int argc, char * argv[])
{
  int * arr;
  int iter;
  int length = 12;
  int total;
  arr = malloc(length * sizeof(int));
  if (arr == NULL)
    {
      printf("malloc fails.\n");
      return EXIT_FAILURE;
    }
  for (iter = 0; iter < length; iter ++)
    {
      arr[iter] = iter;
    }
  total = sum(arr, length);
  printf("Total is %d.\n", total);
  free (arr);
  return EXIT_SUCCESS;
}
