#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 200

/* ���� ������� � ����� */
const unsigned n = 5;
/* ������� �� ��������� �� ����� */
const char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 1 },
  { 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0 }
};

char used[MAXN];

/* ������������ DFS */
void DFS(unsigned i)
{ unsigned k;
  used[i] = 1;
  for (k = 0; k < n; k++)
    if (A[i][k] && !used[k]) DFS(k);
  printf("%u ", i + 1);
}

int main(void) {
  unsigned i;
  /* ������������� */
  for (i = 0; i < n; i++) used[i] = 0;
  printf("����������� ��������� (� ������� ���): \n");
  for (i = 0; i < n; i++)
    if (!used[i]) DFS(i);
  printf("\n");
  return 0;
}
