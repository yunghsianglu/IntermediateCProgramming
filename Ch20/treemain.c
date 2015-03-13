// main.c
#include "tree.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char * argv[])
{
  TreeNode * root = NULL;
  int num = 0;
  int iter;
  unsigned int seed = time(NULL);
  seed = 0;
  srand(seed);
  if (argc >= 2)
    {
      num = (int) strtol(argv[1], NULL, 10);
    }
  if (num < 8)
    {
      num = 8;
    }
  int * array = malloc(sizeof(int) * num);
  for (iter = 0; iter < num; iter ++)
    {
      array[iter] = rand() % 10000;
    }
  for (iter = 0; iter < num; iter ++)
    {
      int val = array[iter];
      printf("insert %d\n", val);
      root = Tree_insert(root, val);
      Tree_print(root);
    }
  for (iter = 0; iter < num; iter ++)
    {
      int index = rand() % (2 * num); 
      if (index < num)
	{
	  int val = array[index];
	  printf("delete %d\n", val);
	  root = Tree_delete(root, val);
	  Tree_print(root);
	}
    }
  Tree_destroy(root);
  free (array);
  return EXIT_SUCCESS;
}
