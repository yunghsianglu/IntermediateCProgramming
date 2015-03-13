// dateofbirth.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  int year;
  int month;
  int date;
} DateOfBirth;
DateOfBirth DateOfBirth_construct(int y, int m, int d)
{
  DateOfBirth dob;
  dob.year = y;
  dob.month = m;
  dob.date = d;
  return dob;
}

void DateOfBirth_print(DateOfBirth d)
{
  printf("Date of Birth: %d/%d/%d\n", 
	 d.year, d.month, d.date);
}

typedef struct
{
  char * name;
  DateOfBirth dob;
} Person;

Person * Person_construct(char * n, int y, int m, int d);
void Person_destruct(Person * p);

// create a new object by copying the attributes of p 
Person * Person_copy(Person * p); 

// p1 is already an object, make its attribute the 
// same as p2's attributes
Person * Person_assign(Person * p1, Person * p2);

void Person_print(Person * p);

int main(int argc, char * argv[])
{
  Person * p1 = Person_construct("Amy", 1989, 8, 21);
  Person * p2 = Person_construct("Jennifer", 1991, 2, 17);
  Person * p3 = Person_copy(p1); // create p3
  Person_print(p1);
  Person_print(p2);
  Person_print(p3);
  p3 = Person_assign(p3, p2); // change p3
  Person_print(p3);
  Person_destruct(p1);
  Person_destruct(p2);
  Person_destruct(p3);
  return EXIT_SUCCESS;
}

Person * Person_construct(char * n, int y, int m, int d)
{
  Person * p;
  p = malloc(sizeof(Person));
  if (p == NULL)
    {
      printf("malloc fail\n");
      return NULL;
    }
  p -> name = malloc(sizeof(char) * (strlen(n) + 1));
  // + 1 for the ending character '\0' 
  strcpy(p -> name, n);
  p -> dob = DateOfBirth_construct(y, m, d);
  return p;
}

void Person_destruct(Person * p)
{
  // p must be released after p -> name has been released
  free (p -> name);
  free (p);
}

Person * Person_copy(Person * p)
{
  return Person_construct(p -> name, p -> dob.year, 
			  p -> dob.month, p -> dob.date);
}

Person * Person_assign(Person * p1, Person * p2)
{
  free(p1 -> name);

  p1 -> dob = p2 -> dob;
  p1 -> name = strdup(p2 -> name);

  return p1;
}

void Person_print(Person * p)
{
  printf("Name: %s. ", p -> name);
  DateOfBirth_print(p -> dob);
}

