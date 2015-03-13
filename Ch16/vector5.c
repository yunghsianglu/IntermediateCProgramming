// vector5.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
Vector Vector_construct(int a, int b, int c)
{
  Vector v;
  v.x = a;
  v.y = b;
  v.z = c;
  return v;
}

void Vector_print(Vector v)
{
  printf("The vector is (%d, %d, %d).\n", v.x, v.y, v.z);
}

int main(int argc, char * argv[])
{
  Vector v1 = Vector_construct(3, 6, -2);
  Vector_print(v1);
  return EXIT_SUCCESS;
}
