// main.c
#include "encode.h"
#include "constant.h"
#include <stdlib.h>
#include <string.h>
int main(int argc, char ** argv)
{
  // argv[1]: "e" encode 
  //          "d" decode 
  // argv[2]: name of input file
  // argv[3]: name of output file
  if (argc != 4)
    {
      return EXIT_FAILURE;
    }
  if (strcmp(argv[1], "e") == 0)
    {
      encode(argv[2], argv[3]);
    }
  if (strcmp(argv[1], "d") == 0)
    {
      decode(argv[2], argv[3]);
    }
  return EXIT_SUCCESS;
}
