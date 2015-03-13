// bmpimage.h
#ifndef _BMPIMAGE_H
#define _BMPIMAGE_H
#include "bmpheader.h"
typedef struct
{
  BMP_Header header;
  unsigned int data_size;
  unsigned int width;
  unsigned int height;
  unsigned int bytes_per_pixel; 
  unsigned char * data;
} BMP_Image;
#endif
