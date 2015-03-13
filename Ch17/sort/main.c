// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
int main(int argc, char * argv[])
{
  // argv[1]: name of input file
  // argv[2]: name of output file (sort by name)
  // argv[3]: name of output file (sort by age)
  if (argc < 4)
    {
      return EXIT_FAILURE;
    }
  PersonDatabase * perdb = Person_read(argv[1]);
  if (perdb == NULL)
    {
      return EXIT_FAILURE;
    }
  // Person_print(perdb);
  Person_sortByName(perdb);
  // Person_print(perdb);
  if (Person_write(argv[2], perdb) == 0)
    {
      Person_destruct(perdb);
      return EXIT_FAILURE;
    }
  Person_sortByAge(perdb);
  // Person_print(perdb);
  if (Person_write(argv[3], perdb) == 0)
    {
      Person_destruct(perdb);
      return EXIT_FAILURE;
    }
  Person_destruct(perdb);
  return EXIT_SUCCESS;
}

