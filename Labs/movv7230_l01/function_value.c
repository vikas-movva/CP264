/*
* Code example for CP264 Data Structures II
* Pass value to functions
* HBF
*/
#include <stdio.h>
int max(int, int);      // function prototype declaration

int main(){
  int a = 2, b = 3, c;  // local variables of main() function
  c = max(a, b);        // pass value of a and b as parameters for function call of max()
  printf("Max of %d and %d is %d\n", a, b, c);
}

int max(int x, int y){   // x, y are argument variables
  int z;                 // local variable
  z = x > y? x:y;        // equivalent to  if (x>y) z = x; else z=y;
  return z;              
}

/* output:
Max of 2 and 3 is 3
*/