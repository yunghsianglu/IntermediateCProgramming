// vectormalloc.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
Vector * Vector_construct(int a, int b, int c) 
// notice * 
{
  Vector * v;
  v = malloc(sizeof(Vector));
  if (v == NULL) // allocation fail 
    {
      printf("malloc fail\n");
      return NULL;
    }
  v -> x = a;
  v -> y = b;
  v -> z = c;
  return v;
}

void Vector_destruct(Vector * v)
{
  free (v);
}

void Vector_print(Vector * v)
{
  printf("The vector is (%d, %d, %d).\n",
	 v -> x, v -> y, v -> z);
}

int main(int argc, char * argv[])
{
  Vector * v1;
  v1 = Vector_construct(3, 6, -2);
  if (v1 == NULL)
    {
      return EXIT_FAILURE;
    }
  Vector_print(v1);
  Vector_destruct(v1);
  return EXIT_SUCCESS;
}
