#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

void print_bit_string(int len, int x)
{
  char b[20];
  b[0] = '\0';
  int z = len;
 
  for ( ; z > 0; z >>= 1)
    {
      strcat(b, ((x & z) == z) ? "1" : "0");
    }
  printf("%s ", b); 
}

typedef struct {
  unsigned a:2;   // has has 2 bits
  unsigned b:6;   // has has 6 bits
  unsigned c:4;   // has has 4 bits
  unsigned d:4;   // has has 4 bits
  int i:16;        // has 16 bits
} packetType;


typedef struct { 
unsigned char a: 2; 
unsigned char b: 1; 
unsigned char c : 1; 
unsigned char d : 4; 
} flagtype; 


int main(void)
{
  printf("size of packetType = %d\n", sizeof(packetType));
  packetType data;
  data.a = 3; 
  data.b = 7; 
  data.c = 9; 
  data.d = 15; 
  data.i = 256;
  printf("packet in decimal format\n");
  printf("%d, %d, %d, %d, %d\n", data.a, data.b, data.c, data.d, data.i);
 
  printf("packet in various format\n");
  printf("%u, %o, %x, %d, %i\n", data.a, data.b, data.c, data.d, data.i);

  printf("packet in binary format\n");
  print_bit_string(2, data.a);   // len = pow(2, bitnumber-1)
  print_bit_string(32, data.b);
  print_bit_string(8, data.c);
  print_bit_string(8, data.d);
  print_bit_string(32768, data.i);
  printf("\n");

 
  
  printf("size of flagtype = %d\n", sizeof(flagtype));
  flagtype data1;
  data1.a = 3;
  data1.b = 1;
  data1.c = 0;
  data1.d = 7;
  printf("packet in decimal format\n");
  printf("%d, %d, %d, %d\n", data1.a, data1.b, data1.c, data1.d);


  printf("packet in binary format\n");
  print_bit_string(2, data1.a);   // len = pow(2, bitnumber-1)
  print_bit_string(1, data1.b);
  print_bit_string(1, data1.c);
  print_bit_string(8, data1.d);
  printf("\n");

  return 0;
}

/*
size of packetType = 4
packet in decimal format
3, 7, 9, 15, 256
packet in various format
3, 7, 9, 15, 256
packet in binary format
11 000111 1001 1111 0000000100000000
size of flagtype = 1
packet in decimal format
3, 1, 0, 7
packet in binary format
11 1 0 0111
*/
