// bits.c
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int main ( int argc , char * * argv )
{
  unsigned char a = 129;    // decimal 129, hexadecimal 0X81
  unsigned char b = 0XF0;   // decimal 240
  unsigned char c = a & b;  // hexadecimal 0X80, decimal 128
  printf("%d, %X\n", c, c); // 128, 80 
  unsigned char d = a | b;  // hexadecimal 0XF1, decimal 241
  printf("%d, %X\n", d, d); // 241, F1
  unsigned char e = d << 3; // hexadecimal 0X88, decimal 136
  printf("%d, %X\n", e, e); // 136, 88
  unsigned char f = d >> 2; // hexadecimal 0X3C, decimal 60
  printf("%d, %X\n", f, f); // 60, 3C
  return EXIT_SUCCESS ;
}
