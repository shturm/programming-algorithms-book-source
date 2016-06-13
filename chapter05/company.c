#include <stdio.h>

/* ���������� ���� �������� (������� � �����) */
#define MAXN 150

/* ���� �������� (������� � �����) */
const unsigned n = 6;
const unsigned m = 1;        /* T����� ��� �������� ���������� �������� 1 */

/* ������� �� ��������� �� ����� */
const unsigned A[MAXN][MAXN] = {
  { 0,  8, 40, 20, 55, 20 },
  { 0,  0,  0,  0,  0, 25 },
  { 0,  0,  0,  0,  0, 10 },
  { 0, 45,  0,  0,  0,  0 },
  { 0,  0,  0, 31,  0,  0 },
  { 0,  0,  0,  0,  0,  0 }
};

unsigned control[MAXN];
char used[MAXN];

void addControls(void)
{ unsigned i, j;
  for (i = 0; i < n; i++)
    /* ��� �������� i � ��� �������, ��������� ������� ������ ��� ���� �� m */
    if (control[i] > 50 && !used[i]) {
      for (j = 0; j < n; j++) control[j] += A[i][j];
      used[i] = 1;
    }
}

void solve(void)
{ unsigned i;
  for (i = 0; i < n; i++) {
    control[i] = 0;
    used[i] = 0;
  }
  for (i = 0; i < n; i++) control[i] = A[m-1][i];
  for (i = 0; i < n; i++) addControls();
}

void printResult(void) {
  unsigned i;
  printf("�������� %d ���������� �������� ��������: \n", m);
  for (i = 0; i < n; i++)
    if (control[i] > 50) printf("%u: %3u% \n", i, control[i]);
  printf("\n");
}

void main(void) {
  solve();
  printResult();
}
