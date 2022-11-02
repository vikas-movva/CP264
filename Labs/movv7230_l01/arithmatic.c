/*
 * Code example for CP264 Data Structures II
 * Testing arithmetic operations with (forced) casting and overflow
 * HBF
*/
#include <stdio.h>

int main() {
   int a=5, b=2; 
   printf("&a:%lu\n", &a);
   printf("&b:%lu\n", &b);
   
   int e = 256 + 'A';
   char k = (char) *(&e);
   float c = 1.0, d = 2.0; 
   
   printf("a=%d\n", a);
   printf("b=%d\n", b);
   printf("a/b=%d\n", a/b);
   printf("a/b=%f\n", (float) (a/b));
   printf("a/b=%f\n", (float) a/b);
   printf("c/d=%f\n", c/d);
   printf("c/b=%f\n", c/b);
   
   printf("k:%c\n", k);
   printf("&b:%lu\n", &b);
   printf("&e:%lu\n", &e);
   printf("&k:%lu\n", &k);
   
   int g = 2147483647;   // 2^31-1, the maximum positive value of int
   int h = g+1;          // will be out of int range, over-flow
   printf("g=%d\n", g);
   printf("h=%d\n", h);  // -2147483648, not correct due to over-flow
   
   return 0;
}

/*
&a:6422268
&b:6422264
a=5
b=2
a/b=2
a/b=2.000000
a/b=2.500000
c/d=0.500000
c/b=0.500000
k:A
&b:6422264
&e:6422260
&k:6422259
g=2147483647
h=-2147483648
*/