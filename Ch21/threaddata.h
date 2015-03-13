// threaddata.h
#ifndef THREADDATA_H
#define THREADDATA_H
typedef struct
{
  unsigned int minval;
  unsigned int maxval;
  int numSol;
  int * setA;
  int sizeA;
  int kval;
} ThreadData;
#endif
