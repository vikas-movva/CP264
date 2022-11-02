/*
 * Code example for CP264 Data Structures II
 * Testing variable casting
 * HBF
*/
#include <stdio.h>

int main() {
  int a = 'a' + 256;
  char b = a;
  printf("a=%d\n", a);
  printf("b=%d\n", b);	
	
	
  float c = 10000.1;
  int d = c; 
  double e = d;
  printf("c=%f\n", c);
  printf("c=%10.1f\n", c);
  printf("d=%d\n", d);
  printf("e=%f\n", e);  
  return 0;
}

/*output
a=353
b=97
c=10000.099609
c=   10000.1
d=10000
e=10000.000000
*/