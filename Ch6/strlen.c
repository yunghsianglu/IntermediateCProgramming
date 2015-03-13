// strlen.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  char str1[] = {'T','h','i','s',' ','n','v','t'};
  char str2[] = {'T','h','i','s',' ','s','t','r','0'};
  char str3[] = {'2','n','d',' ','s','t','\0','M'};
  char str4[] = {'C',' ','P',' ','@','-','\0','1','8','k'};
  char str5[6];
  int len3;
  int len4;
  int len5;
  str5[0] = 'H';
  str5[1] = 'e';
  str5[2] = 'l';
  str5[3] = 'l';
  str5[4] = 'o';
  str5[5] = '\0';     
  len3 = strlen(str3);
  len4 = strlen(str4);
  len5 = strlen(str5);
  printf("len3 = %d,len4 = %d,len5 = %d\n",len3,len4,len5);
  return EXIT_SUCCESS;
}
