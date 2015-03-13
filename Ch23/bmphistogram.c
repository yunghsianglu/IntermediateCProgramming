// bmphistogram.c
#include "bmpfunc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// the width and height of the histogram
// WIDTH must be 255 or larger
#define HIST_WIDTH    256
#define HIST_HEIGHT   200
void BMP_histogram(BMP_Image *img)
{
  // find the frequencies of the intensity of each color
  int * redfreq   = malloc(sizeof(int) * HIST_WIDTH);
  int * greenfreq = malloc(sizeof(int) * HIST_WIDTH);
  int * bluefreq  = malloc(sizeof(int) * HIST_WIDTH);
  // set all values to zero
  bzero(redfreq, sizeof(int) * HIST_WIDTH);
  bzero(greenfreq, sizeof(int) * HIST_WIDTH);
  bzero(bluefreq, sizeof(int) * HIST_WIDTH);

  // count the frequencies
  int pxl;
  for (pxl = 0; pxl < (img -> data_size); pxl += 3)
    {
      redfreq[img -> data[pxl + 2]] ++;
      greenfreq[img -> data[pxl + 1]] ++;
      bluefreq[img -> data[pxl]] ++;
    }

  // find the maximum of the value
  int maxval = 0;
  int ind;
  for (ind = 0; ind < HIST_WIDTH; ind ++)
    {
      if (maxval < redfreq[ind])
	{
	  maxval = redfreq[ind];
	}
      if (maxval < greenfreq[ind])
	{
	  maxval = greenfreq[ind];
	}
      if (maxval < bluefreq[ind])
	{
	  maxval = bluefreq[ind];
	}
    }
  maxval ++; 
  // make it larger than the larget number so that the
  // indexes will be between 0 and HEIGHT - 1
  // adjust the metadata
  img -> width  = HIST_WIDTH;
  img -> height = HIST_HEIGHT;
  img -> data_size = 
    HIST_WIDTH * HIST_HEIGHT * (img -> bytes_per_pixel);
  (img -> header).width  = HIST_WIDTH;
  (img -> header).height = HIST_HEIGHT;
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
  int brightness;
  for (brightness = 0; brightness < HIST_WIDTH; 
       brightness ++)
    {
      // find the (x,y) coordinate
      // x: brightness, same as ind
      // y: frequency, scaled by the histogram's height
      //    and the maximum value
      int xval = brightness;
      int yval = HIST_HEIGHT - 
	HIST_HEIGHT * redfreq[brightness] / maxval;
      yval --; // this will be beween 0 and HEIGHT - 1
      ind = 3 * (yval * HIST_WIDTH + xval) + 2;
      img -> data[ind] = 255;
      // printf("xval = %d, yval = %d, ind = %d\n", 
      //       xval, yval, ind);

      yval = HIST_HEIGHT - 
	HIST_HEIGHT * greenfreq[brightness] / maxval;
      yval --; 
      ind = 3 * (yval * HIST_WIDTH + xval) + 1;
      img -> data[ind] = 255;

      yval = HIST_HEIGHT - 
	HIST_HEIGHT * bluefreq[brightness] / maxval;
      yval --; 
      ind = 3 * (yval * HIST_WIDTH + xval);
      img -> data[ind] = 255;
    }
  free (redfreq);
  free (greenfreq);
  free (bluefreq);
}
