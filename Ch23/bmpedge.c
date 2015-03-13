// bmpedge.c
#include "bmpfunc.h"
#include <stdlib.h>
static int RGB2Gray(char red, char green, char blue)
{
  // this is a commonly used formula
  double gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
  return (int) gray;
}
void BMP_edge(BMP_Image *img, int thrshd)
{
  // create a two-dimension array for the gray level 
  int width  = img -> width;
  int height = img -> height;
  char * * twoDGray = malloc(sizeof(char *) * height);
  int row;
  int col;
  for (row = 0; row < height; row ++)
    {
      twoDGray[row] = malloc(sizeof(char *) * width);
    }
  // convert RGB to gray
  int pxl = 0;
  for (row = 0; row < height; row ++)
    {
      for (col = 0; col < width; col ++)
	{
	  twoDGray[row][col] = RGB2Gray(img -> data[pxl + 2],
					img -> data[pxl + 1],
					img -> data[pxl]);
	  pxl += 3;
	}
    }
  // detect edges and save the edges in the image
  pxl = 0;
  for (row = 0; row < height; row ++)
    {
      pxl += 3; // skip the first pixel in each row
      for (col = 1; col < width; col ++)
	{
	  int diff = twoDGray[row][col] - 
	    twoDGray[row][col - 1];
	  // take the absolute value
	  if (diff < 0)
	    {
	      diff = - diff;
	    }
	  if (diff > thrshd) // an edge
	    {
	      // set color to white
	      img -> data[pxl + 2] = 255;
	      img -> data[pxl + 1] = 255;
	      img -> data[pxl]     = 255;
	    }
	  else // not an edge
	    {
	      // set color to black
	      img -> data[pxl + 2] = 0;
	      img -> data[pxl + 1] = 0;
	      img -> data[pxl]     = 0;
	    }
	  pxl += 3;
	}
    }
  for (row = 0; row < height; row ++)
    {
      free(twoDGray[row]);
    }
  free (twoDGray);
}
