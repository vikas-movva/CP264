/*
 * Code example for CP264 Data Structures II
 * Testing bitwise operations
 * HBF
*/

#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

void print_bit_string(unsigned int len, int x)
{
  char b[40];
  b[0] = '\0';
  unsigned int z = len;
 
  for ( ; z > 0; z >>= 1) {
    strcat(b, ((x & z) == z) ? "1" : "0");
  }
  printf("%s ", b); 
}

int main(void)
{

  unsigned int a = 60;      /* 60 = 00000000 00000000 00000000 00111100 */  
  unsigned int b = 13;      /* 13 = 00000000 00000000 00000000 00001101 */
  unsigned int c = a & b;   /* 12 = 00000000 00000000 00000000 00001100 */ 

  printf("a   = ");
  print_bit_string(2147483648, a);
  printf("\n");

  printf("b   = ");
  print_bit_string(2147483648, b);
  printf("\n");

  printf("a&b = ");
  print_bit_string(2147483648, c); 
  printf("\n");

  c = a | b;                /* 61 = 00000000 00000000 00000000 00111101 */ 
  printf("a|b = ");
  print_bit_string(2147483648, c);
  printf("\n");

  c = a ^ b;                /* 49 = 00000000 00000000 00000000 00110001 */ 
  printf("a^b = ");
  print_bit_string(2147483648, c);
  printf("\n");

 
  a = ~a;                   /* ~a = 11111111 11111111 11111111 11000011   */      
  printf("~a  = ");
  print_bit_string(2147483648, a);
  printf("\n");

  unsigned int value = 4;   /*  4 = 00000000 00000000 00000000 00000100 */  
  unsigned int shift = 2;
  printf("value = %d\n", value);

  value = value << shift;   /* 16 = 00000000 00000000 00000000 00010000 */
  printf("value << 2 = %d = ", value);
  print_bit_string(2147483648, value);
  printf("\n");

  value <<= shift; 
  printf("value << 2 = %d = ", value);
  print_bit_string(2147483648, value);
  printf("\n");

  int bytes=256;    
  do {
    printf("%3ld ", bytes);
    bytes  >>=  1;     
  } while (bytes);

  return 0;
}

/*
a   = 00000000000000000000000000111100
b   = 00000000000000000000000000001101
a&b = 00000000000000000000000000001100
a|b = 00000000000000000000000000111101
a^b = 00000000000000000000000000110001
~a  = 11111111111111111111111111000011
value = 4
value << 2 = 16 = 00000000000000000000000000010000
value << 2 = 64 = 00000000000000000000000001000000
256 128  64  32  16   8   4   2   1
*/
