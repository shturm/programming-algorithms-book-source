#include <stdio.h>
#define MAX 100

unsigned m[MAX][MAX];

void copyMatrix(unsigned stX, unsigned stY, unsigned cnt, unsigned add)
{ unsigned i, j;
  for (i = 0; i < cnt; i++)
    for (j = 0; j < cnt; j++)
	  m[i + stX][j + stY] = m[i + 1][j + 1] + add;
}

void findSolution(unsigned n) /* ��������� ��������� */
{ unsigned i, j;
  if (n % 2 == 0) /* ��� n � �����, �������� �� ������ ��� n-1 */
	n--;

  /* ��������� �� ��������� �� n - ��� � ����������� �������. */
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
	  m[i][j] = i + j < n ? i + j + 1 : i + j + 1 - n;

  /* �������������� �� ���������� �� n */
  if (n % 2 == 1) n++;

  for (i = 0; i < n; i++) {
    if (n % 2 == 0)     /* ��������� �� ��������� ����� � ��� ��� ����� n */
      m[i][n - 1] = m[n - 1][i] = m[i][i];
    m[i][i] = 0;        /* ��������� � 0 �� ������� �������� */
  }
}

void print(unsigned n)        /* ������� ��������� */
{ unsigned i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
	  printf("%3u", m[i][j]);
    printf("\n");
  }
}

int main(void) {
  const unsigned n = 5;
  findSolution(n);
  print(n);
  return 0;
}