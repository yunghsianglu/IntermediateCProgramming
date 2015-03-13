// main.c
#include <stdio.h>
#include <stdlib.h>
#include "decpack.h"
int main ( int argc , char * * argv )
{
  DecPack * dp = DecPack_create(5);
  int iter;
  for (iter = 0; iter < 21 ; iter ++)
    {
      DecPack_insert(dp, iter % 10);
    }
  DecPack_print(dp);
  for (iter = 0; iter < 7 ; iter ++)
    {
      printf("delete %d\n", DecPack_delete(dp));
    }
  DecPack_print(dp);
  for (iter = 0; iter < 6 ; iter ++)
    {
      DecPack_insert(dp, iter % 10);
    }
  DecPack_print(dp);
  for (iter = 0; iter < 6 ; iter ++)
    {
      printf("delete %d\n", DecPack_delete(dp));
    }
  DecPack_print(dp);
  DecPack_destroy(dp);
  return EXIT_SUCCESS ;
}
