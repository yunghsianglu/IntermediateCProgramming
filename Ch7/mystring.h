// mystring.h
#ifndef MYSTRING_H
#define MYSTRING_H
/*
 * Count the number of characters in a string.
 * Example: my_strlen("foo") should be 3.
 */
int my_strlen(const char * str);

/* ---------------------------------------------------- */
/*
 * Count the number of occurrences of a particular 
 * character c in a string.
 *
 * Example: my_countchar("foo", 'o') should be 2.
 */
int my_countchar(const char * str, char c);

/* ---------------------------------------------------- */
/*
 * Convert a string to uppercase.  Only alphabetical 
 * characters should be converted; numbers and symbols 
 * should not be affected. Hint: toupper(c) is a macro 
 * that is the uppercase version of a character c.
 *
 * Example: char * str = "foobar";
 * my_strupper(foobar) is "FOOBAR".
 */
void my_strupper(char * str);

/* ---------------------------------------------------- */
/*
 * Return the pointer to the first occurrence of the character
 * If the character is not in the string, return NULL.
 *
 * Example: char * str = "foobar";
 * my_strchr(foobar, 'b') is the address of str[3]
 */

char * my_strchr(const char * str, char ch);


#endif /* MYSTRING_H */
