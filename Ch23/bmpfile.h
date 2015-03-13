// bmpfile.h
#ifndef _BMPFILE_H_
#define _BMPFILE_H_
#include "bmpimage.h"
// open a BMP image given a filename
// return a pointer to a BMP image if success
// returns NULL if failure.
BMP_Image *BMP_open(const char *filename);
// save a BMP image to the given a filename 
// return 0 if failure
// return 1 if success
int BMP_save(const BMP_Image *image, const char *filename);
// release the memory of a BMP image structure
void BMP_destroy(BMP_Image *image);
#endif
