// parallel.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "threaddata.h"
#include "subsetsum.h"
#define NUMBER_THREAD 16
void * checkRange(void * range)
{
  ThreadData * thd = (ThreadData *) range;
  unsigned int minval = thd -> minval;
  unsigned int maxval = thd -> maxval;
  // printf("minval = %d, maxval = %d\n", minval, maxval);
  unsigned int ind;
  // caution: need to use <= for max
  for (ind = minval; ind <= maxval; ind ++)
    {
      thd -> numSol += 
	subsetEqual(thd -> setA, thd -> sizeA, 
		    thd -> kval, ind);
    }
  return NULL;
}

int subsetSum(int * setA, int sizeA, int kval)
// This function does not allocate memory (malloc)
// No need to free memory if failure occurs
{
  
  pthread_t tid[NUMBER_THREAD];
  ThreadData thd[NUMBER_THREAD];
  // set the values for the thread data
  unsigned int maxCode = 1;
  unsigned int ind;
  for (ind = 0; ind < sizeA; ind ++)
    {
      maxCode *= 2;
    }
  int total = 0;
  unsigned int minval = 1;
  unsigned int size = maxCode / NUMBER_THREAD;
  unsigned int maxval = size;
  for (ind = 0; ind < NUMBER_THREAD - 1; ind ++)
    {
      thd[ind].minval = minval;
      thd[ind].maxval = maxval;
      thd[ind].numSol = 0;
      thd[ind].setA = setA;
      thd[ind].sizeA = sizeA;
      thd[ind].kval = kval;
      minval = maxval + 1;
      maxval += size;
    }
  // ind should be NUMBER_THREAD - 1 now
  // handle the last thread differently because
  // maxCode may not be a multiple of NUMBER_THREAD
  thd[ind].minval = minval;
  thd[ind].maxval = maxCode - 1; // remember -1
  thd[ind].numSol = 0;
  thd[ind].setA = setA;
  thd[ind].sizeA = sizeA;
  thd[ind].kval = kval;
  
  // create the threads
  for (ind = 0; ind < NUMBER_THREAD; ind ++)
    {
      int rtv;
      rtv = pthread_create(& tid[ind], NULL,
			   checkRange, (void *) & thd[ind]);
      if (rtv != 0)
	{
	  printf("ERROR: pthread_crate() fail\n");
	}
    }

  // wait for the threads to complete
  for (ind = 0; ind < NUMBER_THREAD; ind ++)
    {
      int rtv;
      rtv = pthread_join(tid[ind], NULL);
      if (rtv != 0)
	{
	  printf("ERROR; pthread_join() returns %d\n", rtv);
	  return EXIT_FAILURE;
	}
      total += thd[ind].numSol;
    }
  return total;
}

