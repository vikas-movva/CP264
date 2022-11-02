/* 
* Code example for CP264 Data Structures II
* testing flow control and command line argument
* file: primes.c
* compute primes between [a, b] for integers 1 <= a <= b <= 2^31 - 1
* HBF 
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *args[]) {
  int i, k, m = 2, a = 1, b = 1, prime_count = 0, max = 2147483647;

  if ( argc == 1 ) {
    printf("Need one or two integer arguments in range 1 < a < b < 2^31-1");
    return 0;
  } else if ( argc == 2 ) {
    b = atoi( args[1] );
  } else {
    a = atoi( args[1] );
    b = atoi( args[2] );
  }

  if (1 <= a && a <= b && b < max ) {
    for ( i = a; i <= b; i++) {
      if (i <= 3) {
        printf("%5ld  ", i);
        prime_count++;
        continue;
      }
      
      if (i%2 == 0 || i%3 == 0) continue;
     
	  k = (int) sqrt( i );
      for ( m = 5; m <= k; m++) {
        if (i%m == 0) break;
      }
      
      if (m >= k+1){
        printf("%5ld  ", i);
        prime_count++;
        if ( prime_count % 10 == 0 ) {
          printf("\n");
        }      
      }
    }
  } else {
    printf("The integer arguments are not in range 1 < a < b < 2^31-1");
  }

  printf("\nTotal %d prime numbers within [%d, %d]\n", prime_count, a, b);

  return 0;
}

/*
$gcc primes.c -o primes
$primes 100 200
ouptut:
  101    103    107    109    113    127    131    137    139    149
  151    157    163    167    173    179    181    191    193    197
  199
Total 21 prime numbers within [100, 200]
*/

