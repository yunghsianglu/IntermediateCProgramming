// person.h
#ifndef PERSON_H
#define PERSON_H
typedef struct
{
  int age;
  char * name;
} Person;

typedef struct
{
  int number; // number of persons
  Person * * person; // array of pointers to Person objects
} PersonDatabase;

// read person database from a file
// person is an array of pointers to person objects
// The function returns the pointer of a database or NULL
// The function returns NULL if reading from the file fails

PersonDatabase * Person_read(char * filename);

void Person_sortByName(PersonDatabase * perdb);

void Person_sortByAge(PersonDatabase * perdb);

// save the database in a file
// return 0 if fail
// return 1 if succeed
int Person_write(char * filename, PersonDatabase * perdb);

// write to computer screen
void Person_print(PersonDatabase * perdb);

// release the memory of the database
void Person_destruct(PersonDatabase * perdb);

#endif
