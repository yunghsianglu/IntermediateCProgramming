/* maze.c */
#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
// A static function can be called by another function
// in the same file. A static function cannot be called 
// by any function outside this file. 
// If ptr is NULL, print an error message and exit
static void checkMalloc(void * ptr, char * message);
// find the length of a line in a file (EOF or '\n') 
static int findLineLength(FILE * fh);
// Find the numbers of rows and columns. If the maze is not
// rectangular, use the widest row 
static void Maze_findSize(FILE * fh, int * numRow, 
			  int * numCol);
static void checkMalloc(void * ptr, char * message)
{
  if (ptr == NULL) // malloc fail 
    {
      printf("malloc for %s fail\n", message);
    }
}
static int findLineLength(FILE * fh)
{
  int ch;
  int length = 0;
  if (feof(fh)) { return -1; }
  do
    {
      ch = fgetc(fh); // read one character 
      length ++;
    } while ((ch != '\n') && (ch != EOF));
  return length; 
}
static void Maze_findSize(FILE * fh, int * numRow, int * numCol)
{
  int row = 0;
  int col = 0;
  int maxCol = 0;
  // find the maximum number of columns. This allows the 
  // program to handle a maze that is not rectangular.
  do
    {
      col = findLineLength(fh);
      if (col != -1)
	{
	  if (maxCol < col) { maxCol = col; }
	  row ++; 	  
	}
    } while (col != -1); 
  * numRow = row;
  * numCol = maxCol;
}
Maze * Maze_construct(char * fileName)
{
  int numRow = 0;
  int numCol = 0;
  int row, col;
  int ch;
  FILE * fptr = fopen(fileName, "r");
  if (fptr == 0)
    {
      fprintf(stderr, "open %s fail\n", fileName);
      return NULL;
    }
  Maze_findSize(fptr, & numRow, & numCol);
  Maze * mzptr = malloc(sizeof(Maze));
  checkMalloc(mzptr, "mzptr");
  mzptr -> numRow = numRow;
  mzptr -> numCol = numCol;
  // create a two-dimensional array to store the cells 
  mzptr -> cells = malloc(numRow * sizeof(int *));
  checkMalloc(mzptr -> cells, "mzptr -> cells");
  for (row = 0; row < numRow; row ++)
    {
      mzptr -> cells[row] = malloc(numCol * sizeof(int));
      checkMalloc(mzptr -> cells[row], 
			 "mzptr -> cells[row]");
      // initialize the cells to invalid 
      for (col = 0; col < numCol; col ++)
	{
	  (mzptr -> cells)[row][col] = INVALIDSYMBOL;
	}
    }
  // move fptr to the beginning 
  fseek(fptr, 0, SEEK_SET);

  // read the file again and fill the two-dimensional array
  row = 0;
  while ((! feof(fptr)) && (ch != EOF) && (row < numRow))
    {
      // fill one row 
      col = 0;
      do 
	{
	  ch = fgetc(fptr);
	  if (ch != EOF) 
	    {
	      // notice that '\n' is also stored 
	      (mzptr -> cells)[row][col] = ch;
	      switch (ch)
		{
		case STARTSYMBOL:
		  mzptr -> startRow = row;
		  mzptr -> startCol = col;
		  mzptr -> curRow = row;
		  mzptr -> curCol = col;
		  break;
		case EXITSYMBOL:
		  mzptr -> exitRow = row;
		  mzptr -> exitCol = col;
		  break;
		}
	      col ++;
	    }
	} while ((ch != EOF) && (ch != '\n'));
      // checking '\n" to handle non-rectangular mazes
      row ++;
    }
  fclose(fptr);
  return mzptr;
}

// release the memory 
void Maze_destruct(Maze * mzptr)
{
  int row;
  for (row = 0; row < (mzptr -> numRow); row ++)
    { free ((mzptr -> cells)[row]); }
  free (mzptr -> cells);
  free(mzptr);
}

void Maze_print(Maze * mzptr)
{
  int row;
  int col;
  for (row = 0; row < (mzptr -> numRow); row ++)
    {
      for (col = 0; col < (mzptr -> numCol); col ++)
	{
	  if (((mzptr -> curRow) == row) && 
	      ((mzptr -> curCol) == col))
	    {
	      if (((mzptr -> curRow) == (mzptr -> startRow)) && 
		  ((mzptr -> curCol) == (mzptr -> startCol)))
		{
		  printf("s");
		}
	      else
		{
		  printf("c");
		}
	    }
	  else
	    {
	      printf("%c", (mzptr -> cells)[row][col]);
	    }
	}
      printf("\n");
    }
}
