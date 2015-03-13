// freq.h
#ifndef FREQ_H
#define FREQ_H
typedef struct
{
  char value;
  int freq;
} CharFreq;
// count the frequencies of the letters
// NUMLETTER is a constant (128) defined in constant.h
// frequencies is an array of NUMLETTER elements
// The function returns the number of characters in the file
// The function returns 0 if cannot read from the file
int countFrequency(char * filename, CharFreq * frequencies);
// print the array
void printFrequency(CharFreq * frequencies);
// sort the array
void sortFrequency(CharFreq * frequencies);
#endif
