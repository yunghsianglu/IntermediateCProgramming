// utility.h
#ifndef UTILITY_H
#define UTILITY_H
#include <stdio.h>
// write one bit to a file

// whichbit indicates which bit this is written to (0 means 
// left most, 7 means right most)
// curbyte is the current byte
//
// if whichbit is zero, curbyte is reset and bit is put 
// to the leftmost bit
// 
// when which bit reaches 7, this byte is written to the 
// file and whichbit is reset
// 
// the function returns 1 if a byte is written to the file
//              returns 0 if no byte is written
//                     -1 if it tries to write and fails
int writeBit(FILE * fptr, unsigned char bit, 
	     unsigned char * whichbit, unsigned char * curbyte);
// if * whichbit is not 0, some bits of * curbyte are not used
// fill these bits by 0 and write the byte to the file
int padZero(FILE * fptr, unsigned char * whichbit, 
	    unsigned char * curbyte);

int readBit(FILE * fptr, unsigned char * bit,
	    unsigned char * whichbit, 
	    unsigned char * curbyte);
#endif
