#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct csr_t {
  int  n;   /* Dimension of matrix (assume square) */
  int* pr;  /* Array of matrix nonzeros (row major order) */
  int* col; /* Column indices of nonzeros *
  int* ptr; /* Offsets of the start of each row in pr
               (ptr[n] = number of nonzeros) */
} csr_t;

// assume result initizialized to zeros
void sparse_multiply(csr_t* A, double* x, double* result)
{
  int col = (A->ptr)[0];
  int colNext;
  int n = scr_t->n;
  for (int i = 0; i < n; i++) {
    colNext = (A->ptr)[i+1];
    while (col < colNext) {
      result[i] += (A->pr)[colStart] * X[(csr_t->col)[col]];
      col++;
    }
  }
} 


int main()
{
    int n = 4;
    double pr[7]  = { 1.,-1.,  1.,-1.,  1.,-1.,  1. };
    int col[7]    = { 0,  1,   1,  2,   2,  3,   3  };
    int ptr[5]    = { 0, 2, 4, 6, 7 };
    csr_t A = { n, pr, col, ptr };
    double x[4] = {1., 3., 8., 12.};
    double result[4];
    sparse_multiply(&A, x, result);

    /*
     * Should compute
     * [-1,  1,  0,  0 ]   [ 1  ]
     * [ 0, -1,  1,  0 ] * [ 3  ]
     * [ 0,  0, -1,  1 ]   [ 8  ]
     * [ 0,  0,  0,  1 ]   [ 12 ]
     */
    for (int i = 0; i < n; ++i)
        printf(" %g\n", result[i]);
}
