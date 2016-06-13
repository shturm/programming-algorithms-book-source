#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 150

/* ���� ������� � ����� */
const unsigned n = 10;
/* ������� �� ��������� �� ����� */
const char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }
};

char used[MAXN];
unsigned postnum[MAXN], count = 0;

/* ��������� � ��������� ��� ��������� �� ����������� */
void DFS(unsigned i)
{ unsigned j;
  used[i] = 1;
  for (j = 0; j < n; j++)
    if (!used[j] && A[i][j]) DFS(j);
  postnum[i] = count++;
}

/* ��������� � ��������� �� ����� G� */
void backDFS(unsigned i)
{ unsigned j;
  printf("%u ", i + 1);
  count++; used[i] = 1;
  for (j = 0; j < n; j++)
    if (!used[j] && A[j][i]) backDFS(j);
}

/* ������ ����� ���������� ���������� �� ����� */
void strongComponents(void)
{ unsigned i;
  for (i = 0; i < n; i++) used[i] = 0;
  while (count < n - 1) {
    for (i = 0; i < n; i++)
      if (!used[i]) DFS(i);
  }
  for (i = 0; i < n; i++) used[i] = 0;
  count = 0;
  while (count < n - 1) {
    unsigned max = 0, maxv = 0;
    for (i = 0; i < n; i++)
      if (!used[i] && postnum[i] > max) {
        max = postnum[i];
        maxv = i;
      }
    printf("{ ");
    backDFS(maxv);
    printf("}\n");
  }
}

int main(void) {
  printf("����� ���������� ���������� � ����� ��:\n");
  strongComponents();
  return 0;
}
