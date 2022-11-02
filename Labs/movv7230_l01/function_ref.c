/*
* Code example for CP264 Data Structures II
* Pass reference to functions
* HBF
*/
#include<stdio.h>

int main( void ) {
  int a = 2;
  inc(&a);        // pass the reference of a to function call of inc().         
  printf("a=%i\n", a);  
  return 0;
}

void inc(int *x) { // argument variable x holds the address of parameter variable.  
  *x =  *x + 1;    // increase the value at memory address x. 
}

/*
a=3
*/
