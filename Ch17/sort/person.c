// person.c
#include "person.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
PersonDatabase * Person_read(char * filename)
{
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return NULL;
    }
  PersonDatabase * perdb = malloc(sizeof(PersonDatabase));
  if (perdb == NULL)
    {
      fclose (fptr);
      return NULL;
    }
  // count the number of people in the file
  // use the longest name for the size of the buffer
  int numPerson = 0;
  int longestName = 0; // length of buffer to read names
  while (! feof(fptr))
    {
      int age;
      // find a line that contains a number (age)
      if (fscanf(fptr, "%d", & age) == 1)
	{
	  numPerson ++;
	  // the remaning characters are the name
	  int nameLength = 0;
	  while ((!feof (fptr)) && (fgetc(fptr) != '\n'))
	    {
	      nameLength ++;
	    }
	  nameLength ++; // for '\n'
	  if (longestName < nameLength)
	    {
	      longestName = nameLength;
	    }
	}
    }
  // the number of person is known now
  perdb -> number = numPerson;
  perdb -> person = malloc(sizeof(Person*) * numPerson);
  
  // allocate a buffer to read the names
  char * name = malloc(sizeof(char) * longestName);
  int ind = 0;

  // read the file again and store the data in the database
  // return to the beginning of the file
  fseek (fptr, 0, SEEK_SET);
  while (! feof(fptr))
    {
      int age;
      if (fscanf(fptr, "%d", & age) == 1)
	{
	  // remove the space separating age and name
	  fgetc(fptr); 
	  fgets(name, longestName, fptr);

	  // remove '\n'
	  char * chptr = strchr(name, '\n');
	  if (chptr != NULL) // last line may not have '\n'
	    {
	      * chptr = '\0';
	    }

	  perdb -> person[ind] = malloc(sizeof(Person));
	  perdb -> person[ind] -> age = age;
	  // strdup calls malloc
	  perdb -> person[ind] -> name = strdup(name);
	  ind ++;
	}
    }
  free (name);
  fclose (fptr);
  return perdb;
}

static void Person_writeHelp(FILE * fptr, 
			     PersonDatabase * perdb)
{
  int ind;
  for (ind = 0; ind < perdb -> number; ind ++)
    {
      // write one person per line
      fprintf(fptr, "%d %s\n", 
	      perdb -> person[ind] -> age,
	      perdb -> person[ind] -> name);
    }
}

void Person_print(PersonDatabase * perdb)
{
  printf("---------------------------------------\n");
  // stdout is a built-in FILE *
  // stdout means the output is sent to the computer screen
  // not a file on the disk
  Person_writeHelp(stdout, perdb);
}

int Person_write(char * filename, PersonDatabase * perdb)
{
  if (perdb == NULL)
    {
      // nothing in the database
      return 0;
    }
  FILE * fptr = fopen(filename, "w");
  if (fptr == NULL)
    {
      // cannot open the file
      return 0;
    }
  Person_writeHelp(fptr, perdb);
  fclose (fptr);
  return 1;
}

static int comparebyName(const void * p1,
			 const void * p2)
{
  // get addresses of the array elements
  const Person * * pp1 = (const Person * *) p1; 
  const Person * * pp2 = (const Person * *) p2;
  // get the elements
  const Person const * pv1 = * pp1;
  const Person const * pv2 = * pp2;
  // compare the attributes
  return strcmp((pv1 -> name), (pv2 -> name));
}

void Person_sortByName(PersonDatabase * perdb)
{
  qsort(perdb -> person, perdb -> number,
	sizeof(Person *), comparebyName);
}

static int comparebyAge(const void * p1,
			const void * p2)
{
  const Person * * pp1 = (const Person * *) p1;
  const Person * * pp2 = (const Person * *) p2;
  const Person * pv1 = * pp1;
  const Person * pv2 = * pp2;
  return ((pv1 -> age) - (pv2 -> age));
}

void Person_sortByAge(PersonDatabase * perdb)
{
  qsort(perdb -> person, perdb -> number,
	sizeof(Person *), comparebyAge);
}

void Person_destruct(PersonDatabase * perdb)
{
  int ind;
  for (ind = 0; ind < perdb -> number; ind ++)
    {
      free (perdb -> person[ind] -> name);
      free (perdb -> person[ind]);
    }
  free (perdb -> person);
  free (perdb);
}
