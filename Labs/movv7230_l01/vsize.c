/*
 * Code example for CP264 Data Structures II
 * Testing for data type size and variable type, size, and value representation
 * HBF
*/
#include <stdio.h>

int main() {
	
  printf("sizeof(char):%d, sizeof(int):%d, sizeof(float):%d, sizeof(double):%d\n", sizeof(char), sizeof(int), sizeof(float), sizeof(double));
  
  char a = 'a'; 
  printf("char: %c, %d, %d\n", a, a, sizeof(a));
  
  int b = 1;
  printf("int:  %d, %d\n", b, sizeof(b));

  short int c = 1234;
  printf("short int:  %d, %d\n", c, sizeof(c));

  long int d = 222222222; 
  printf("long int:  %ld, %d\n", d, sizeof(d));

  float e = 3.1415926; // single precision      
  printf("float: %f, %d\n", e, sizeof(e));
  
  float e1 = 1.2e-5; // floating number of scientific notation      
  printf("1.2e-5 %f, %d\n", e1, sizeof(e1));
 
  double f = 2.33333333333; // double precision
  printf("double %14.11lf, %d\n", f, sizeof(f));
  
  int g = 0xAA;  // hex
  printf("dec/hex/oct number: %d, %x, %o\n", g, g, g);
  
  int h = 016; // oct
  printf("dec/hex/oct number: %d, %x, %o\n", h, h, h);
    
  return 0;
}

/*
sizeof(char):1, sizeof(int):4, sizeof(float):4, sizeof(double):8
char: a, 97, 1
int:  1, 4
short int:  1234, 2
long int:  222222222, 4
float: 3.141593, 4
1.2e-5 0.000012, 4
double  2.33333333333, 8
dec/hex/oct number: 170, aa, 252
dec/hex/oct number: 14, e, 16
*/