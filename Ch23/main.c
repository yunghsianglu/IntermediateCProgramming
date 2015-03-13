// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmpimage.h"
#include "bmpfile.h"
#include "bmpfunc.h"
#define THRESHOLD 140
int main(int argc, char **argv)
{
  // Check arguments
  if (argc < 4) 
    {
      printf("Usage: image <input> <function> <output>\n");
      return EXIT_FAILURE;
    }

  // open the input file
  BMP_Image *img = BMP_open(argv[1]);
  if (img == NULL) 
    {
      return EXIT_FAILURE;
    }
  if (strcmp(argv[2], "invert") == 0)
    {
      BMP_invert(img);
    }
  if (strcmp(argv[2], "red") == 0)
    {
      BMP_color(img, 2);
    }
  if (strcmp(argv[2], "green") == 0)
    {
      BMP_color(img, 1);
    }
  if (strcmp(argv[2], "blue") == 0)
    {
      BMP_color(img, 0);
    }
  if (strcmp(argv[2], "edge") == 0)
    {
      BMP_edge(img, THRESHOLD);
    }
  if (strcmp(argv[2], "gray") == 0)
    {
      BMP_gray(img);
    }
  if (strcmp(argv[2], "equalize") == 0)
    {
      BMP_equalize(img);
    }
  /*
  if (strcmp(argv[2], "histogram") == 0)
    {
      BMP_histogram(img);
    }
  */
  if (strcmp(argv[2], "checker") == 0)
    {
      BMP_checker(img);
    }
  if (strcmp(argv[2], "mix") == 0)
    {
      BMP_mix(img);
    }

  // Save the file
  if (BMP_save(img, argv[3]) == 0)
    {
      printf("Output file invalid!\n");
      BMP_destroy(img);
      return EXIT_FAILURE;	
  }
  // Destroy the BMP image
  BMP_destroy(img);
  return EXIT_SUCCESS;
}
