/* maze.h */
#ifndef MAZE_H
#define MAZE_H
#define STARTSYMBOL    's'
#define EXITSYMBOL     'E'
#define BRICKSYMBOL    '*'
#define CORRIDORSYMBOL ' '
#define INVALIDSYMBOL  '-'
typedef struct
{
  int numRow, numCol;     // size of the maze 
  int startRow, startCol; // starting location 
  int exitRow, exitCol;   // exit location 
  int curRow, curCol;     // current location 
  // brick? exit? starting point? corridor? 2-dimensional 
  // array storing the cells
  int * * cells;
} Maze;
// directions, ORIGIN marks the starting point 
enum {ORIGIN, EAST, SOUTH, WEST, NORTH};
// move forward, backward, or found exit alread
enum {FORWARD, BACKWARD, DONE};
// read the maze from a file 
Maze * Maze_construct(char * fileName);
// release memory before the program ends 
void Maze_destruct(Maze * mz);
// print the maze's properties (mainly for debugging) 
void Maze_print(Maze * mz);
#endif
