/*
* Code example for CP264 Data Structures II
* Compute n! by recursive algorithm (i.e. recursive function call), and by iterative algorithm
* HBF
*/
#include <stdio.h>
int rfactorial(int n);
int ifactorial(int n); 

void main(){
  int n = 1, y = 1;
  printf("Input an integer:");
  scanf("%d",&n);
  
  y = rfactorial(n);
  printf("%d! = %d\n", n, y);

  y = ifactorial(n);
  printf("%d! = %d\n", n, y);  
}

int rfactorial(int n) {
  if (n <= 1) return 1;
  return n*rfactorial(n-1);
}

int ifactorial(int n) {
  if (n <=1) return 1;
  int i, r=1;
  for (i=1;i<=n; i++)
    r *= i;
  return r;
}

/*
Input an integer:10
10! = 3628800
10! = 3628800
*/
