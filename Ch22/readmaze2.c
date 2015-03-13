// readmaze.c
// read a maze file and store it in a two-dimensional array

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
  FILE * fptr;
  int ch;
  int row = 0; 
  int column = 0;
  int numberRow, numberColumn;
  int * * mazeArr;
  if (argc < 2)
    {
      printf("Need to provide the file's name.\n");
      return EXIT_FAILURE;
    }
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("fopen fail.\n");
      return EXIT_FAILURE;
    }
  numberColumn = 0;
  // get the numbers of rows and columns 
  do
    {
      ch = fgetc(fptr);
      if (ch != EOF)
	{
	  if (ch == '\n')
	    {
	      row ++;
	      numberColumn = column;
	      column = 0;
	    }
	  else
	    {
	      column ++;
	    }
	}
    } while (ch != EOF);
  numberRow = row;
  // allocate memory for the mazeArr 
  mazeArr = malloc(numberRow * sizeof (int *));
  for (row = 0; row < numberRow; row ++)
    {
      mazeArr[row] = malloc(numberColumn * sizeof (int));
    }
  // return to the beginning of the file 
  fseek(fptr, 0, SEEK_SET);
  // read the file again and fill the two-dimensional array
  row = 0;
  column = 0;
  do 
    {
      ch = fgetc(fptr);
      if (ch != EOF)
	{
	  if (ch == '\n')
	    {
	      row ++;
	      column = 0;
	    }
	  else
	    {
	      mazeArr[row][column] = ch;
	      column ++;
	    }
	}
    } while (ch != EOF);
  fclose(fptr);
  printf("The mazeArr has %d rows and %d columns.\n", 
	 numberRow, numberColumn);
  for (row = 0; row < numberRow; row ++)
    {
      for (column = 0; column < numberColumn; column ++)
	{
	  printf("%c", mazeArr[row][column]);
	}      
      printf("\n");
    }
  // release the memory 
  for (row = 0; row < numberRow; row ++)
    {
      free (mazeArr[row]);
    }
  free (mazeArr);
  return EXIT_SUCCESS;
}
