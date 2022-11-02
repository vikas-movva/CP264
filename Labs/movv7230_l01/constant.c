/*
 * Code example for CP264 Data Structures II
 * Testing constants
 * HBF
*/
#include <stdio.h>
#define PI 3.1415926  // define constant PI by macro

int main() {
  float r = 1;
  float area = PI*r*r; 
  float cf = 2*PI*r; 
  printf("radius=%f\n", r);
  printf("area=%f\n", area);
  printf("circumference=%f\n", cf);
  const float pi = 3.1415926;  // declare pi a read-only variable
  r = 2.0;
  area = pi*r*r;
  cf = 2*pi*r;
  printf("radius=%f\n", r);  
  printf("area=%f\n", area);
  printf("circumference=%f\n", cf);
  //pi = 3.14;  //not allowed to change value of pi, uncomment this line see what happens in compiling. 
  return 0;
}

/*
radius=1.000000
area=3.141593
circumference=6.283185
radius=2.000000
area=12.566370
circumference=12.566370
*/