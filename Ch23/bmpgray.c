// bmpgray.c
#include "bmpfunc.h"
#include <stdlib.h>
static int RGB2Gray(char red, char green, char blue)
{
  // this is a commonly ued formula
  double gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
  return (int) gray;
}

void BMP_gray(BMP_Image *img)
{
  int pxl;
  for (pxl = 0; pxl < (img -> data_size); pxl += 3)
    {
      unsigned char gray = RGB2Gray(img -> data[pxl + 2],
				    img -> data[pxl + 1],
				    img -> data[pxl]);
      img -> data[pxl + 2] = gray;
      img -> data[pxl + 1] = gray;
      img -> data[pxl]     = gray;
    }
}
