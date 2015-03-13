// main.c
#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"
int main(int  argc, char ** argv)
{
  if (argc != 4) 
    {
      return EXIT_FAILURE;
    }
  Node * arr1 = List_read(argv[1]);
  if (arr1 == NULL)
    {
      return EXIT_FAILURE;
    }
  Node * arr2 = List_read(argv[2]);
  if (arr2 == NULL)
    {
      List_destroy(arr2);
      return EXIT_FAILURE;
    }
  Node * arr3 = List_merge(arr1, arr2);
  int ret = List_save(argv[3], arr3);
  List_destroy(arr1);
  List_destroy(arr2);
  List_destroy(arr3);
  if (ret == 0)
    {
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
