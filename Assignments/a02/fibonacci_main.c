/*
--------------------------------------------------
Project: cp264oc-a2q1
File:    fibonacci_main.c public test driver
Author:  HBF
Version  2021-05-11
--------------------------------------------------
*/
#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int *la;
int *ha;

int main(){
	int i=0, n = 40;
	clock_t t1, t2;	

	printf("**Iterative algorithm measurement**\n");
	ha = &i;
	la = ha;
	printf("iterative_fibonacci(%d):%d\n", n, iterative_fibonacci(n));
	printf("high address:%lu\n", ha);
	printf("low address:%lu\n", la);
	int memory_span1 = (unsigned long) ha - (unsigned long) la;
	printf("iterative_fibonacci(%d) memory span:%d\n", n, memory_span1);

	//run time measuring for iterative_fibonacci
	int m1 = 500000;
	t1=clock();
	for (i=0; i< m1; i++) {
	  iterative_fibonacci(n);
	}
	t2=clock();
	double time_span1 = (double) t2-t1;
	printf("time_span(iterative_fibonacci(%d) for %d times):%0.1f (ms)\n", n, m1, time_span1);
		
	printf("\n**Recursive algorithm measurement**\n");
	la = ha;
	printf("recursive_fibonacci(%d):%d\n", n, recursive_fibonacci(n));
	printf("high address:%lu\n", ha);
	printf("low address:%lu\n", la);
	int memory_span2 = (unsigned long) ha - (unsigned long) la;
	printf("recursive_fibonacci(%d) memory span:%d\n", n, memory_span2);
	//run time measuring recursive_fibonacci
	int m2 = 10;
	t1=clock();
	for (i=0; i<m2; i++) {
      recursive_fibonacci(n);
	}
	t2=clock();
	double time_span2 = t2-t1;
	printf("time_span(recursive_fibonacci(%d) for %d times) in (ms):%0.1f\n", n, m2, time_span2);
	
	printf("\n**Comparison of recursive and iterative algorithms**\n");
	printf("memory_span(recursive_fibonacci(%d))/memory_span(iterative_fibonacci(%d)):%0.1f\n", n, n, ((double) memory_span2)/memory_span1);
	printf("time_span(recursive_fibonacci(%d))/time_span(iterative_fibonacci(%d)):%0.1f\n", n, n, (time_span2/time_span1)*(m1/m2));
	
	return 0;
}

/*
gcc fibonacci.h fibonacci_main.c -o a2q1
a2q1

**Iterative algorithm measurement**
iterative_fibonacci(40):102334155
high address:6684268
low address:6684208
iterative_fibonacci(40) memory span:60
time_span(iterative_fibonacci(40) for 500000 times):74.0 (ms)

**Recursive algorithm measurement**
recursive_fibonacci(40):102334155
high address:6684268
low address:6682992
recursive_fibonacci(40) memory span:1276
time_span(recursive_fibonacci(40) for 10 times) in (ms):9685.0

**Comparison of recursive and iterative algorithms**
memory_span(recursive_fibonacci(40))/memory_span(iterative_fibonacci(40)):21.3
time_span(recursive_fibonacci(40))/time_span(iterative_fibonacci(40)):6543918.9
*/
