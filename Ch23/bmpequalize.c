// bmpequalize.c
#include "bmpfunc.h"
void BMP_equalize(BMP_Image *img)
{
  int pxl;
  unsigned char redmin   = 255;
  unsigned char redmax   = 0;
  unsigned char greenmin = 255;
  unsigned char greenmax = 0;
  unsigned char bluemin  = 255;
  unsigned char bluemax  = 0;
  // find the maximum and the minimum values of each color
  for (pxl = 0; pxl < (img -> data_size); pxl += 3)
    {
      unsigned char red   = img -> data[pxl + 2];
      unsigned char green = img -> data[pxl + 1];
      unsigned char blue  = img -> data[pxl];
      if (redmin > red) { redmin = red; }
      if (redmax < red) { redmax = red; }
      if (greenmin > green) { greenmin = green; }
      if (greenmax < green) { greenmax = green; }
      if (bluemin > blue) { bluemin = blue; }
      if (bluemax < blue) { bluemax = blue; }
    }
  // calculate the scaling factors
  // max and min must be different to prevent
  // divided by zero error
  double redscale   = 1.0;
  double greenscale = 1.0;
  double bluescale  = 1.0;
  if (redmax > redmin) 
    { 
      redscale = 255.0 / (redmax - redmin); 
    }
  if (greenmax > greenmin) 
    { 
      greenscale = 255.0 / (greenmax - greenmin); 
    }
  if (bluemax > bluemin) 
    { 
      bluescale = 255.0 / (bluemax - bluemin); 
    }

  // equalize the pixels
  for (pxl = 0; pxl < (img -> data_size); pxl += 3)
    {
      if (redmax > redmin)
	{
	  img -> data[pxl + 2] = (int) (redscale * 
		   (img -> data[pxl + 2] - redmin));
	}
      if (greenmax > greenmin)
	{
	  img -> data[pxl + 1] = (int) (greenscale * 
		   (img -> data[pxl + 1] - greenmin));
	}
      if (bluemax > bluemin)
	{
	  img -> data[pxl] = (int) (bluescale * 
		   (img -> data[pxl] - bluemin));
	}
    }
}
