// decpack.h
#ifndef DECPACK_H
#define DECPACK_H
typedef struct
{
  int size; // how many digits can be stored
  int used; // how many digits are actually stored
  unsigned char * data; // store the digits
  // size should be 2 * the actually allocated memory because
  // each byte can store two digits
} DecPack;

// create a DecPack object with the given size
DecPack * DecPack_create(int sz);

// Insert a decimal value into the DecPack object. The new 
// value is at the end of the array
void DecPack_insert(DecPack * dp, int val);

// delete and return the last value in the DecPack object
// do not shrink the data array even if nothing is stored
// The returned value should be between 0 and 9
// return -1 if no digit can be deleted
int DecPack_delete(DecPack * dp);

// print the values stored in the object, the first inserted 
// value should be printed first
// the printed values are between '0' and '9'
void DecPack_print(DecPack * dp);

// destroy the whole DecPack object, release all memory
void DecPack_destroy(DecPack * dp);
#endif
