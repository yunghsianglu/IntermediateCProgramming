// vector3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
void printVector(Vector v)
{
  printf("The vector is (%d, %d, %d).\n", v.x, v.y, v.z);
}

int main(int argc, char * argv[])
{
  Vector v1;
  v1.x = 3;
  v1.y = 6;
  v1.z = -2;
  printVector(v1);
  return EXIT_SUCCESS;
}
