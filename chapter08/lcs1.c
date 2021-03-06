#include <stdio.h>
#include <string.h>
#define MAXN 100
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) /* ����� ��-������� �������� */

char F[MAXN][MAXN];               /* ������ ������� */

const char x[MAXN] = "acbcacbcaba";    /* ����� ������ */
const char y[MAXN] = "abacacacababa";  /* ����� ������ */

/* ������ ��������� �� ���-������� ���� ��������� */
unsigned LCS_Length(void)
{ unsigned i, j, m, n;
  m = strlen(x);  /* ������� �� ������� ������ */
  n = strlen(y);  /* ������� �� ������� ������ */
  /* ������� ������������� */
  for (i = 1; i <= m; i++)
	F[i][0] = 0;
  for (j = 0; j <= n; j++)
	F[0][j] = 0;
  /* ������� ����� */
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      if (x[i - 1] == y[j - 1])
        F[i][j] = F[i - 1][j - 1] + 1;
      else
        F[i][j] = MAX(F[i - 1][j], F[i][j - 1]);
  return F[m][n];
}

int main(void) {
  printf("\n������� �� ���-������� ���� ���������: %u", LCS_Length());
  return 0;
}
