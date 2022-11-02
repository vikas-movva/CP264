/* mypow.c
 * Code example for CP264 Data Structures II
 * Computing the power
 * HBF
*/
#include <stdio.h>

// time: O(log n), space: O(1)
int ipow(int b, int n) {
    int r = 1;
	while (n>0) {	   
	   if (n & 1) r *= b;
       n >>= 1;	
	   b *= b;
	}
    return r;
}

// b^n = b^(n/2 * 2 + n%2)
// time: O(log n), space: O(log n)  
int ipow_recursive(int b, int n) {
    int r = 1;
	if (n>0) {
		r = ipow_recursive(b*b, n>>1);
		if (n & 1) r *=b;
	}
	return r;
}

// time: O(n), space: O(1) 
int ipow_slow(int b, int n) {
    int r = 1;
	while (n>0) {
		r *= b;
		n--;
	}
	return r;
}

float fpow(float b, int n) {
    float r = 1.0;
	while (n>0) {	   
	   if (n & 1) r *= b;
       n >>= 1;	
	   b *= b;
	}
    return r;
}

double dpow(double b, int n) {
    double r = 1.0;
	while (n>0) {	   
	   if (n & 1) r *= b;
       n >>= 1;	
	   b *= b;
	}
    return r;
}

int main(){
    int b=2, i, m = 10;
	printf("power by int type:\n");
	for (i = 0; i< m; i++) { 
		printf("power(%d, %d)=%d\n", b, i, ipow(b, i));
	}
		
	printf("power by int type recursion:\n");
	for (i = 0; i< m; i++) { 
		printf("power(%d, %d)=%d\n", b, i, ipow_recursive(b, i));
	}
	
	printf("power by int slow:\n");
	for (i = 0; i< m; i++) { 
		printf("power(%d, %d)=%d\n", b, i, ipow_slow(b, i));
	}	
				
	printf("power by single precision floating type:\n");	
	float fb=2.0;
	for (i = 0; i< m; i++) { 
		printf("power(%f, %d)=%f\n", fb, i, fpow(fb, i));
	}
	
    printf("power by double precision floating type:\n");		
	double db = 2.0;
	for (i = 0; i<m; i++) { 
		printf("power(%f, %d)=%f\n", db, i, dpow(db, i));
	}
	return 0;
}

/*
power(2, 0)=1
power(2, 1)=2
power(2, 2)=4
power(2, 3)=8
power(2, 4)=16
power(2, 5)=32
power(2, 6)=64
power(2, 7)=128
power(2, 8)=256
power(2, 9)=512
power by int type recursion:
power(2, 0)=1
power(2, 1)=2
power(2, 2)=4
power(2, 3)=8
power(2, 4)=16
power(2, 5)=32
power(2, 6)=64
power(2, 7)=128
power(2, 8)=256
power(2, 9)=512
power by int slow:
power(2, 0)=1
power(2, 1)=2
power(2, 2)=4
power(2, 3)=8
power(2, 4)=16
power(2, 5)=32
power(2, 6)=64
power(2, 7)=128
power(2, 8)=256
power(2, 9)=512
power by single precision floating type:
power(2.000000, 0)=1.000000
power(2.000000, 1)=2.000000
power(2.000000, 2)=4.000000
power(2.000000, 3)=8.000000
power(2.000000, 4)=16.000000
power(2.000000, 5)=32.000000
power(2.000000, 6)=64.000000
power(2.000000, 7)=128.000000
power(2.000000, 8)=256.000000
power(2.000000, 9)=512.000000
power by double precision floating type:
power(2.000000, 0)=1.000000
power(2.000000, 1)=2.000000
power(2.000000, 2)=4.000000
power(2.000000, 3)=8.000000
power(2.000000, 4)=16.000000
power(2.000000, 5)=32.000000
power(2.000000, 6)=64.000000
power(2.000000, 7)=128.000000
power(2.000000, 8)=256.000000
power(2.000000, 9)=512.000000
*/
