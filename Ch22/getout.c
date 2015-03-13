// getout.c
#include <stdio.h>
#include "maze.h"
int canMove(Maze * mzptr, int row, int col, int dir);
void getOut(Maze * mzptr, int row, int col, 
	    int dir, int * mode)
{
  printf("Move to (%d,%d)\n", row, col);
  if ((mzptr -> cells)[row][col] == 'E') /* found exit */
    { 
      printf("Found the exit!\n");
      (* mode) = DONE;
    }
  if (((*mode) != DONE) && 
      canMove(mzptr, row, col, EAST) && 
      (dir != WEST))
    {
      (* mode) = FORWARD;
      getOut(mzptr, row, col + 1, EAST, mode); 
      if ((*mode) == BACKWARD)
	{
	  printf("Move to (%d,%d)\n", row, col);
	}
    }
  if (((*mode) != DONE) && 
      canMove(mzptr, row, col, SOUTH) && 
      (dir != NORTH))
    {
      (* mode) = FORWARD;
      getOut(mzptr, row + 1, col, SOUTH, mode); 
      if ((*mode) == BACKWARD)
	{
	  printf("Move to (%d,%d)\n", row, col);
	}
    }
  if (((*mode) != DONE) && 
      canMove(mzptr, row, col, WEST) && 
      (dir != EAST))
    {
      (* mode) = FORWARD;
      getOut(mzptr, row, col - 1, WEST, mode); 
      if ((*mode) == BACKWARD)
	{
	  printf("Move to (%d,%d)\n", row, col);
	}
    }
  if (((*mode) != DONE) &&
      canMove(mzptr, row, col, NORTH) &&
      (dir != SOUTH))
    {
      (* mode) = FORWARD;
      getOut(mzptr, row - 1, col, NORTH, mode); 
      if ((*mode) == BACKWARD)
	{
	  printf("Move to (%d,%d)\n", row, col);
	}
    }
  if ((*mode) != DONE)
    { 
      (* mode) = BACKWARD;
    }
}


