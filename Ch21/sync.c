// sync.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_THREAD 16
typedef struct
{
  int * intptr;
  pthread_mutex_t * mlock;
} ThreadData;

void * threadfunc(void *arg)
{
  ThreadData * td = (ThreadData *) arg;
  int * intptr = td -> intptr;
  pthread_mutex_t * mlock = td -> mlock;
  while (1)
    {
      int rtv;
      rtv = pthread_mutex_lock(mlock); // lock
      // beginning critical section
      if (rtv != 0)
	{
	  printf("mutex_lock fail\n");
	  return NULL;
	}
      (* intptr) ++;
      (* intptr) --;
      if ((* intptr) != 0)
	{
	  printf("value is %d\n", * intptr);
	  return NULL;
	}
      // end critical section
      rtv = pthread_mutex_unlock(mlock); // unlock
      if (rtv != 0)
	{
	  printf("mutex_unlock fail\n");
	  return NULL;
	}
    }
  return NULL;
}

int main (int argc, char *argv[])
{
  pthread_mutex_t mlock;
  pthread_mutex_init(& mlock, NULL);
  int val = 0;
  ThreadData arg;
  arg.intptr = & val;
  arg.mlock  = & mlock;
  pthread_t tid[NUMBER_THREAD];
  int rtv; // return value of pthread_create
  int ind;
  for (ind = 0; ind < NUMBER_THREAD; ind ++)
    {
      rtv = pthread_create(& tid[ind], NULL, 
			   threadfunc, (void *) & arg);
      if (rtv != 0)
	{
	  printf("pthread_create() fail %d\n", rtv);
	  return EXIT_FAILURE;
	}
    }
  for (ind = 0; ind < NUMBER_THREAD; ind ++)
    {
      rtv = pthread_join(tid[ind], NULL);
      if (rtv != 0)
	{
	  printf("pthread_join() fail %d\n", rtv);
	  return EXIT_FAILURE;
	}
    }
  pthread_mutex_destroy(& mlock);
  return EXIT_SUCCESS;
}
