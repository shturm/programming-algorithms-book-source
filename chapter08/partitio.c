#include <stdio.h>
#define MAXN 80
#define INFINITY (unsigned long)(-1)
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) /* ����� ��-������� �������� */

unsigned long p[MAXN];       /* ��������� ���� */
unsigned long F[MAXN][MAXN]; /* ������ ������� */
unsigned long b[MAXN][MAXN]; /* �� �������������� �� ��������� */

const unsigned s[MAXN] = {0,23,15,89,170,25,1,86,80,2,27};  /* ������ (�������� ������� �� �� ������) */
const unsigned n = 10;  /* ���� �������� � �������� */
const unsigned k = 4;   /* ���� ����� */

/* �������� ��������� ��������� �� k ����� */
long doPartition(unsigned k)
{ unsigned i, j, l, m;
  /* ���������� �� ����������� ���� */
  for (p[0] = 0, i = 1; i <= n; i++)
	p[i] = p[i - 1] + s[i];
  /* ������������ �� ���������� ������� */
  for (i = 1; i <= n; i++)
	F[i][1] = p[i];
  for (j = 1; j <= k; j++)
	F[1][j] = s[1];
  /* ������� ����� */
  for (i = 2; i <= n; i++)
    for (j = 2; j <= k; j++)
      for (F[i][j] = INFINITY, l = 1; l <= i - 1; l++)
 	    if ((m = MAX(F[l][j - 1], p[i] - p[l])) < F[i][j]) {
          F[i][j] = m;
          b[i][j] = l;
        }
  return F[n][k];
}

void print(unsigned from, unsigned to)
{ unsigned i;
  printf("\n");
  for (i = from; i <= to; i++)
	printf("%u ", s[i]);
}

void printPartition(unsigned n, unsigned k)
{ if (1 == k)
    print(1, n);
  else {
    printPartition(b[n][k], k - 1);
    print(b[n][k] + 1, n);
  }
}

int main(void) {
  printf("\n���������� ���� � ����� �� �������: %lu", doPartition(k));
  printPartition(n, k);
  return 0;
}