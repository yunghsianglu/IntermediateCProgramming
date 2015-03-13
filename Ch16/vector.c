// vector.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
int main(int argc, char * argv[])
{
  Vector v1;
  v1.x = 3;
  v1.y = 6;
  v1.z = -2;
  printf("The vector is (%d, %d, %d).\n",
	 v1.x, v1.y, v1.z);
  return EXIT_SUCCESS;
}
