#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 150

/* ���� ������� � ����� */
const unsigned n = 7;
const unsigned p = 3;  /* p-������ */

/* ������� �� ������� �� ����� */
int A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 2, 0, 0 },
  { 1, 0, 4, 0, 0, 0, 0 },
  { 0, 4, 0, 3, 0, 5, 0 },
  { 0, 0, 3, 0, 4, 0, 8 },
  { 2, 0, 0, 4, 0, 0, 0 },
  { 0, 0, 5, 0, 0, 0, 2 },
  { 0, 0, 0, 8, 0, 2, 0 }
};

unsigned center[MAXN], pCenter[MAXN], pRadius;

const MAX_VALUE = 10000;

/* ������ ��������� �� ���������� ��� ����� ����� ������ ������� */
void floyd(void)
{ unsigned i, j, k;
  /* ����������� 0 �� �������� �� MAX_VALUE */
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (A[i][j] == 0) A[i][j] = MAX_VALUE;
  /* ��������� �� ����� */
  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (A[i][j] > (A[i][k] + A[k][j]))
          A[i][j] = A[i][k] + A[k][j];

  for (i = 0; i < n; i++) A[i][i] = 0;
}

/* ����������� S �� ������ ������������ ������������ */
void checkSol(void)
{ unsigned i, j, cRadius = 0;

  for (j = 0; j < n; j++) {
    int bT = MAX_VALUE;
    for (i = 0; i < p; i++)
      if (A[center[i]][j] < bT) bT = A[center[i]][j];
    if (cRadius < bT) cRadius = bT;
  }

  if (cRadius < pRadius) {
    pRadius = cRadius;
    for (i = 0; i < p; i++) pCenter[i] = center[i];
  }
}

/* ���������� C(n,p) � ���������� �� ������ p-��������� ������������ �� G */
void generate(unsigned k, unsigned last)
{ unsigned i;
  for (i = last; i < n - p + k; i++) {
    center[k] = i;
    if (k == p)
      checkSol();
    else
      generate(k + 1, i + 1);
  }
}

/* �������� p-������� � p-������� */
void printPCenter(void)
{ unsigned i;
  printf("%u-������� � ����� � �������� ��������� �� �������: {", p);
  for (i = 0; i < p; i++) printf("%d ", pCenter[i] + 1);
  printf("}\n");
  printf("%u-������� � ����� = %u\n", p, pRadius);
}

void main(void) {
  floyd();
  pRadius = MAX_VALUE;
  generate(0, 0);
  printPCenter();
}
