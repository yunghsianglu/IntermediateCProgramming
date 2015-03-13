/* hanoi2.c
 * print the steps moving n disks
 */
#include <stdio.h>
#include <stdlib.h>
void move(int disk, char src, char dest, char additional)
{
  /* Base case */
  if (disk == 1) 
    {
      printf("move disk 1 from %c to %c\n", src, dest);
      return;
    }
  /* Recursive case */
  move(disk - 1, src, additional, dest);
  printf("move disk %d from %c to %c\n", disk, src, dest);
  move(disk - 1, additional, dest, src);
}

int main(int argc, char * argv[])
{
  int n;
  if (argc < 2)
    {
      printf("need one positive integer.\n");
      return EXIT_FAILURE;
    }
  n = (int) strtol(argv[1], NULL, 10);
  if (n <= 0)
    {
      printf("need one positive integer.\n");
      return EXIT_FAILURE;
    }
  move(n, 'A', 'B', 'C');
  return EXIT_SUCCESS;
}
