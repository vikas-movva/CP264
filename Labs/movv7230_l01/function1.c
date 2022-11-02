/*
* Code example for CP264 Data Structures II
* function1.c
* basic concepts of functions in assembly
* HBF
*/

#include<stdio.h>
int a, b;

int add(int x, int y) {
   int z = 1;	
   return x+y+z;
}

int main() {
   a=1;
   b=2;
   add(a, b);
   return 0; 
}

/*
// gcc function1.c -S -o function1.txt
// open function1.txt by a simple editor, derive the following program in assembly language

	.file	"function1.c"
	.comm	_a, 4, 2
	.comm	_b, 4, 2
	.text
	.globl	_add
	.def	_add;	.scl	2;	.type	32;	.endef
_add:
LFB6:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$1, -4(%ebp)
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	addl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE6:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB7:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$1, _a
	movl	$2, _b
	movl	_b, %edx
	movl	_a, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_add
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7:

*/



