// canmove.c
#include "maze.h"
int canMove(Maze * mzptr, int row, int col, int dir)
{
  /* (row, col) is the current location */
  switch (dir)
    {
    case NORTH:
      row --;
      break;
    case SOUTH:
      row ++;
      break;
    case WEST:
      col --;
      break;
    case EAST:
      col ++;
      break;
    }
  int dest = (mzptr->cells)[row][col];
  if ((dest == ' ') || (dest == 'E')) 
    { return 1; } /* corridor or exit, can move to */
  return 0; /* cannot move to */
}
