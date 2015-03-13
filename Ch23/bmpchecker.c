// bmpchecker.c
#include "bmpfunc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define HIST_WIDTH    256
#define HALF_WIDTH    (HIST_WIDTH / 2)
#define QUARTER_WIDTH (HIST_WIDTH / 4)
void BMP_checker(BMP_Image *img)
{
  // resize the image
  img -> width  = HIST_WIDTH;
  img -> height = HIST_WIDTH;
  img -> data_size = 
    HIST_WIDTH * HIST_WIDTH * (img -> bytes_per_pixel);
  (img -> header).width  = HIST_WIDTH;
  (img -> header).height = HIST_WIDTH;
  (img -> header).size = 
    img -> data_size + sizeof(BMP_Header);
  (img -> header).imagesize = img -> data_size;

  // release the memory storing the data
  free (img -> data);

  // allocate memory for the correct size
  img -> data = 
    malloc(sizeof(unsigned char) * (img -> data_size));
  if ((img -> data) == NULL)
    {
      return; 
    }
  
  // set all pixels to black
  bzero(img-> data, 
	sizeof(unsigned char) * (img -> data_size));
  int row;
  int col;
  int ind;
  // lower left corner is white
  int brightness;
  for (row = 0; row < HALF_WIDTH; row ++)
    {
      for (col = 0; col < HALF_WIDTH; col ++)
	{
	  ind = 3 * (row * HIST_WIDTH + col);
	  brightness = 
	    row / QUARTER_WIDTH + col / QUARTER_WIDTH;
	  brightness = 64 * brightness + 127;
	  img -> data[ind] = brightness;
	  img -> data[ind + 1] = brightness;
	  img -> data[ind + 2] = brightness;
	}
    }
  // lower right corner is red
  for (row = 0; row < HALF_WIDTH; row ++)
    {
      for (col = HALF_WIDTH; col < HIST_WIDTH; col ++)
	{
	  brightness =
	    row / QUARTER_WIDTH + col / QUARTER_WIDTH;
	  brightness = 64 * brightness + 63;
	  ind = 3 * (row * HIST_WIDTH + col);
	  img -> data[ind + 2] = brightness;
	}
    }
  // upper left corner is green
  for (row = HALF_WIDTH; row < HIST_WIDTH; row ++)
    {
      for (col = 0; col < HALF_WIDTH; col ++)
	{
	  brightness = 
	    row / QUARTER_WIDTH + col / QUARTER_WIDTH;
	  brightness = 64 * brightness + 63;
	  ind = 3 * (row * HIST_WIDTH + col);
	  img -> data[ind + 1] = brightness;
	}
    }
  // upper right corner is red
  for (row = HALF_WIDTH; row < HIST_WIDTH; row ++)
    {
      for (col = HALF_WIDTH; col < HIST_WIDTH; col ++)
	{
	  brightness = 
	    row / QUARTER_WIDTH + col / QUARTER_WIDTH;
	  brightness = 64 * (brightness - 4) + 127;
	  ind = 3 * (row * HIST_WIDTH + col);
	  img -> data[ind] = brightness;
	}
    }
}
