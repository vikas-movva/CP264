/*
 *  Displays the n by n matrix m in 2D style.
*/
void display_matrix(int *m, int n);

/*
 * Computes and returns the sum of all elements of the n by n matrix m.
*/
int sum(int *m, int n); 

/*
 * Computes and returns if the n by n matrix m is a magic square.
 * returns 1 if true otherwise 0.
 * A square matrix is a magic square if the sum of every row, column, and diagonal is of the same value. 
 * 
*/
int is_magic_square(int *m, int n);

/*
 * Transposes the n by n matrix m1 and save the resulted matrix in m2.
*/
void transpose_matrix(int *m1, int *m2, int n);

/*
 * Computes the matrix multiplication m1*m2 and saves the resulted matrix in m3.
*/
void multiply_matrix(int *m1, int *m2, int *m3, int n);