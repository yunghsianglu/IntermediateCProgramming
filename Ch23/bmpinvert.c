// bmpinvert.c
#include "bmpfunc.h"
void BMP_invert(BMP_Image *img)
{
  int pxl;
  for (pxl = 0; pxl < (img -> data_size); pxl ++)
    {
      img -> data[pxl] = 255 - (img -> data[pxl]);
    }
}
