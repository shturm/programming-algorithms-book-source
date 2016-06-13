#include <stdio.h>
#define MAX 100
#define INFINITY (unsigned long)(-1)

unsigned long m[MAX][MAX];    /* ������� - ������ ������� */

const unsigned long r[MAX+1] = {12,13,35,3,34,2,21,10,21,6}; /* ����������� �� ��������� */
const unsigned n = 9;         /* ���� ������� */

/* ����������� ���������� ������� */
unsigned long solveRecursive(unsigned i, unsigned j)
{ unsigned k;
  if (i == j) return 0;
  m[i][j] = INFINITY;
  for (k = i; k <= j - 1; k++) {
    unsigned long q = solveRecursive(i, k) +
      solveRecursive(k + 1, j) +
      r[i - 1] *
      r[k] *
      r[j];
    if (q < m[i][j])
	  m[i][j] = q;
  }

  return m[i][j];
}

void printMatrix(void) /* ������� ��������� �� ���������� �� ������ */
{ unsigned i,j;
  printf("\n������� �� ����������:");
  for (i = 1; i <= n; i++) {
    printf("\n");
    for (j = 1; j <= n; j++)
      printf("%8lu", m[i][j]);
  }
}

int main(void) {
  printf("\n����������� ���� ��������� �: %lu",solveRecursive(1,n));
  printMatrix();
  return 0;
}
