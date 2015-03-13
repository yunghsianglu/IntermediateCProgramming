// utility.c
#include "utility.h"
int padZero(FILE * fptr, unsigned char * whichbit, 
	    unsigned char * curbyte)
{
  int rtv;
  while ((* whichbit) != 0)
    {
      rtv = writeBit(fptr, 0, whichbit, curbyte);
      if (rtv == -1)
	{
	  return -1;
	}
    }
  return rtv;
}
// write one bit to a file
//
// whichbit indicates which bit this is written to 
// (0 means leftmost, 7 means rightmost)
//
// curbyte is the current byte
//
// if whichbit is zero, curbyte is reset and bit is put 
// to the leftmost bit
// 
// when whichbit reaches 7, this byte is written to the 
// file and whichbit is reset
// 
// the function returns 1 if a byte is written to the file
//              returns 0 if no byte is written
//                     -1 if it tries to write and fails
int writeBit(FILE * fptr, unsigned char bit, 
	     unsigned char * whichbit, 
	     unsigned char * curbyte)
{
  if ((* whichbit) == 0)
    {
      // reset
      * curbyte = 0;
    }
  // shift the bit to the correct location
  unsigned char temp = bit << (7 - (* whichbit));
  * curbyte |= temp; // store the data
  int value = 0;
  if ((* whichbit) == 7)
    {
      int ret;
      ret = fwrite(curbyte, sizeof(unsigned char), 1, fptr);
      // printByte(* curbyte); // for debugging
      if (ret == 1)
	{
	  value = 1;
	}
      else
	{
	  value = -1;
	}
    }
  * whichbit = ((* whichbit) + 1) % 8;
  return value;
}

int readBit(FILE * fptr, unsigned char * bit, 
	    unsigned char * whichbit, unsigned char * curbyte)
  
{
  int ret = 1;
  if ((* whichbit) == 0)
    {
      // read a byte from the file
      ret = fread(curbyte, sizeof(unsigned char), 1, fptr);
    }
  if (ret != 1)
    {
      // read fail
      return -1;
    }
  // shift the bit to the correct location
  unsigned char temp = (* curbyte) >> (7 - (* whichbit));
  temp = temp & 0X01; // get only 1 bit, ignore the others
  // increase by 1
  * whichbit = ((* whichbit) + 1) % 8;
  * bit = temp;
  return 1;
}
