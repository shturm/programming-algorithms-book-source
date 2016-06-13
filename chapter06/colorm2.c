#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 200

/* ���� ������� � ����� */
const unsigned n = 5;
/* ������� �� ��������� �� ����� */
const char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 1 },
  { 1, 0, 1, 1, 1 },
  { 0, 1, 0, 1, 0 },
  { 0, 1, 1, 0, 1 },
  { 1, 1, 0, 1, 0 }};

unsigned col[MAXN], maxCol, count = 0;
char foundSol = 0;

void showSol(void)
{ unsigned i;
  count++;
  printf("��������� ���������� �� �����: \n");
  for (i = 0; i < n; i++) printf("���� %u - � ���� %u \n", i + 1, col[i]);
}

void nextCol(unsigned i)
{ unsigned k, j, success;
  if (i == n) { showSol(); return; }
  for (k = 1; k <= maxCol; k++) {
    col[i] = k;
    success = 1;
    for (j = 0; j < n; j++)
      if (1 == A[i][j] && col[j] == col[i]) {
        success = 0;
        break;
      }
    if (success) nextCol(i + 1);
    col[i] = 0;
  }
}

int main(void) {
  unsigned i;
  for (maxCol = 1; maxCol <= n; maxCol++) {
    for (i = 0; i < n; i++) col[i] = 0;
    nextCol(0);
    if (count) break;
  }
  printf("��� ���� �������� ����������� � %u �����: %u \n", maxCol, count);
  return 0;
}
