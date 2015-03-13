// thread1.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void * printHello(void *arg)
{
  int* intptr = (int *) arg;
  int val = * intptr;
  printf("Hello World! arg = %d\n", val);
  return NULL;
}
int main (int argc, char *argv[])
{
  pthread_t second;
  int rtv; // return value of pthread_create
  int arg = 12345;
  rtv = pthread_create(& second, NULL, 
		       printHello, (void *) & arg);
  if (rtv != 0)
    {
      printf("ERROR; pthread_create() returns %d\n", rtv);
      return EXIT_FAILURE;
    }
  rtv = pthread_join(second, NULL);
  if (rtv != 0)
    {
      printf("ERROR; pthread_join() returns %d\n", rtv);
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
