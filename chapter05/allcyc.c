#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 150

/* ���� ������� � ����� */
const unsigned n = 10;

/* ������ ���������� � ������� �� ���������: 0 - ���� �����; 1 � ��� �����;
 * ��-����� � ������ ������� � 2 �� ��������� ������� �� ����������� ����� �� �����.
 */
char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0, 0 },
  { 1, 0, 1, 1, 0, 0 },
  { 0, 1, 0, 1, 0, 0 },
  { 0, 1, 1, 0, 1, 1 },
  { 0, 0, 0, 1, 0, 1 },
  { 0, 0, 0, 1, 1, 0 }
};

char used[MAXN];
unsigned cycle[MAXN], d;

/* ������ ���������� ��������� ����� */
void DFS(unsigned v)
{ unsigned i;
  used[v] = 1;
  for (i = 0; i < n; i++)
    if (!used[i] && A[v][i]) {
      A[v][i] = 2;
      A[i][v] = 2;
      DFS(i);
    }
}

/* �������� ������� ����� */
void printCycle(void)
{ unsigned k, i;
  for (k = 0; k < d; k++) printf("%u ", cycle[k] + 1);
  printf("\n");
}

/* �������� �� ���� ����� ������ ���������� ��������� ����� */
void DFS2(unsigned v, unsigned u)
{ unsigned k, i;
  if (v == u) { printCycle(); return; }
  used[v] = 1;
  for (i = 0; i < n; i++)
    if (!used[i] && 2==A[v][i]) {
      cycle[d++] = i;
      DFS2(i, u);
      d--;
    }
}

int main(void) {
  unsigned i, j, k;
  DFS(0);
  printf("�������������(��������) ����� � ����� ��: \n");
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (1 == A[i][j]) {
        for (k = 0; k < n; k++) used[k] = 0;
        d = 1;
        cycle[0] = i;
        DFS2(i, j);
      }
  return 0;
}
