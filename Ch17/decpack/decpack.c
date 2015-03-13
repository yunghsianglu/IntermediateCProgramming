// decpack.c
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "decpack.h"
DecPack * DecPack_create(int sz)
{
  // allocate memory for DecPack
  DecPack * dp = malloc(sizeof(DecPack));

  // check whether allocation fails
  if (dp == NULL)
    {
      return NULL;
    }

  // initialize size to sz and used to 0
  dp -> size = sz;
  dp -> used = 0;

  // allocate memory for data, should be only sz/2 because 
  // each byte can store two digits
  
  // if sz is odd, increment sz by one
  if ((sz % 2) == 1) { sz ++; }
  dp -> data = malloc(sizeof(unsigned char) * (sz / 2));

  // check whether allocation fails
  if (dp -> data == NULL)
    {
      free (dp);
      return NULL;
    }

  // return the allocate memory
  return dp;
}

void DecPack_insert(DecPack * dp, int val)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return; }

  // if val < 0 or val > 9, ignore and do nothing
  if ((val < 0) || (val > 9)) { return; }

  // If the allocated memory is full, double the size, 
  // allocate memory for the new size, copy the data, 
  // and insert the new value
  int used = dp -> used;
  if (used == dp -> size) 
    {
      unsigned char * newdata = 
	malloc(sizeof(unsigned char) * (dp -> size));
      int iter;
      for (iter = 0; iter < used; iter ++)
	{
	  newdata[iter / 2] = dp -> data[iter / 2];
	}
      (dp -> size) *= 2;
      free (dp -> data);
      dp -> data = newdata;
    }

  // If used is an even number, the inserted value should 
  // use the upper (left) 4 bits.
  // If used is an odd number, the inserted value should 
  // use the lower (right) 4 bits.
  // 
  // careful: do not lose the data already stored in DecPack
  if ((used % 2) == 0)
    {
      // shifting left adds zeros for the lower bits
      dp -> data[used / 2] = (val << 4);
    }
  else
    {
      // reset the lower four bits, may be left from delete
      unsigned char upper = dp -> data[used / 2] & 0XF0;
      dp -> data[used / 2] = upper + val;
    }
  (dp -> used) ++;
}

int DecPack_delete(DecPack * dp)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return -1; }
  // return -1 if the DecPack object stores no data
  if ((dp -> used) == 0) { return -1; }
  // If used is even, the returned value is the upper 
  // (left) 4 bits. Make sure the returned value is between
  // 0 and 9. If used is odd, the returned value is the 
  // lower (right) 4 bits. Make sure the returned value 
  // is between 0 and 9.
  int val;
  // decrement the used attribute in the DecPack object
  (dp -> used) --;
  int used = dp -> used;
  if ((used % 2) == 0)
    {
      val = dp -> data[used / 2] >> 4;
    }
  else
    {
      val = (dp -> data[used / 2]) & 0X0F;
    }
  // return the value
  return val;
}

void DecPack_print(DecPack * dp)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return; }
  int iter;
  int used = dp -> used;
  
  // go through every value stored in the data attribute
  for (iter = 0; iter < used; iter ++)
    {
      if ((iter % 2) == 0)
	{
	  printf("%d", (dp-> data[iter / 2] >> 4));
	}
      else
	{
	  printf("%d", (dp-> data[iter / 2] & 0X0F));
	}	
    }
  printf("\n");
}

void DecPack_destroy(DecPack * dp)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return; }
  // release the memory for the data
  free (dp -> data);
  // release the memory for the object
  free (dp);
}
