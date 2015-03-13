// bmpmix.c (mix colors)
#include "bmpfunc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define HIST_WIDTH    256
#define HALF_WIDTH    (HIST_WIDTH / 2)
#define QUARTER_WIDTH (HIST_WIDTH / 4)
void BMP_mix(BMP_Image *img)
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

  // draw red 
  int centerx = 127;
  int centery = 80;
  int radius  = 70;
  int row;
  int col;
  for (col = centerx - radius; col < centerx + radius; 
       col ++)
    {
      int xval = col - centerx;
      int yrange = 
	(int) sqrt(radius * radius - xval * xval);
      for (row = centery - yrange; row < centery + yrange; 
	   row ++)
	{
	  int ind = 3 * (row * HIST_WIDTH + col);
	  img -> data[ind + 2] = 255;
	}
    }
  
  // draw green
  centerx = 87;
  centery = 167;
  for (col = centerx - radius; col < centerx + radius; 
       col ++)
    {
      int xval = col - centerx;
      int yrange = 
	(int) sqrt(radius * radius - xval * xval);
      for (row = centery - yrange; row < centery + yrange; 
	   row ++)
	{
	  int ind = 3 * (row * HIST_WIDTH + col);
	  img -> data[ind + 1] = 255;
	}
    }

  // draw blue
  centerx = 167;
  centery = 167;
  for (col = centerx - radius; col < centerx + radius; 
       col ++)
    {
      int xval = col - centerx;
      int yrange = 
	(int) sqrt(radius * radius - xval * xval);
      for (row = centery - yrange; row < centery + yrange; 
	   row ++)
	{
	  int ind = 3 * (row * HIST_WIDTH + col);
	  img -> data[ind] = 255;
	}
    }

}
