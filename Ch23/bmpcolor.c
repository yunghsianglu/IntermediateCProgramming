// bmpcolor.c
#include "bmpfunc.h"
void BMP_color(BMP_Image *img, int clr)
{
  int pxl;
  for (pxl = clr; pxl < (img -> data_size); pxl ++)
    {
      // set the other color components to zero
      if ((pxl % 3) != clr)
	{
	  img -> data[pxl] = 0;
	}
    }
}
