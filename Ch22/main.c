#include <stdio.h>
#include "maze.h"
void getOut(Maze * mzptr, int row, int col, 
	    int dir, int * mode);
int main(int argc, char * argv[])
{
  if (argc < 2)
    {
      fprintf(stderr, "need a file name\n");
      return -1;
    }
  Maze * mzptr = Maze_construct(argv[1]);
  if (mzptr == 0) { return -1; }
  /* Maze_print(mzptr); */
  int progress = FORWARD;
  getOut(mzptr, mzptr -> startRow, mzptr -> startCol, 
	 ORIGIN, & progress); 
  Maze_destruct(mzptr);
  return 0;
}
