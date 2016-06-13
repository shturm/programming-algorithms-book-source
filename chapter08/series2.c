#include <stdio.h>

#define MAX 100
#define q (1 - (p))                 /* ���������� B �� ������� ������� ��� */

const float p = 0.5;                /* ���������� A �� ������� ������� ��� */
const unsigned n = 5;

struct {
  char calculated;                  /* ����������� �� � ���� ����������? */
  float value;                      /* ����������� �������� */
} PS[MAX][MAX];

float pDyn(unsigned i, unsigned j)  /* ��������� ���������� */
{ if (!PS[i][j].calculated) {
    PS[i][j].value = p * pDyn(i - 1, j) + q * pDyn(i, j - 1);
    PS[i][j].calculated = 1;
  }
  return PS[i][j].value;
}

float pDynamic(unsigned i, unsigned j)
{ unsigned k, l;
  for (k = 1; k <= i; k++)
    for (l = 1; l <= j; l++)
	  PS[k][l].calculated = 0;
  for (k = 1; k <= i; k++) {
    PS[0][k].value = 1.0;
    PS[0][k].calculated = 1;
  }
  for (k = 1; k <= j; k++) {
    PS[k][0].value = 0.0;
    PS[k][0].calculated = 1;
  }
  return pDyn(i, j);
}

int main(void) {
  unsigned  i, j;
  pDynamic(n,n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%f ", PS[i][j].value);
    printf("\n");
  }
  return 0;
}