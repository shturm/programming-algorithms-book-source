#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 200

/* ���� ������� � ����� */
const unsigned n = 8;
/* ������� �� ��������� �� ����� */
char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

char used[MAXN];
unsigned topsort[MAXN], total = 0;

void printSort(void)
{ unsigned i;
  printf("����������� ��������� ����� %u: ", ++total);
  for (i = 0; i < n; i++) printf("%u ", topsort[i] + 1);
  printf("\n");
}

void fullTopSort(unsigned count)
{ unsigned i, j, k, saved[MAXN];

  if (count == n) { printSort(); return; }

  /* ������ ������ ������� ��� ������������� */
  for (i = 0; i < n; i++) {
    if (!used[i]) {
      for (j = 0; j < n; j++)
        if (A[j][i]) break;
      if (j == n) {
        for (k = 0; k < n; k++) {
          saved[k] = A[i][k]; A[i][k] = 0;
        }
        used[i] = 1;
        topsort[count] = i;
        fullTopSort(count + 1); /* �������� */
        used[i] = 0;
        for (k = 0; k < n; k++) A[i][k] = saved[k];
      }
    }
  }
}

int main(void) {
  unsigned i;
  for (i = 0; i < n; i++) used[i] = 0;
  fullTopSort(0);
  return 0;
}
