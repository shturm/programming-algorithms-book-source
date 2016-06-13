#include <stdio.h>
#define  MAXN 30           /* ���������� ���� �������� */
#define  MAXM 1000         /* ���������� ���������� �� �������� */

unsigned F[MAXN][MAXM];    /* ������ ������� */

const unsigned m[MAXN] = {0,1,2,3,5,6,7};      /* ����� �� ���������� */
const unsigned c[MAXN] = {0,1,10,19,22,25,30}; /* ���� �� ���������� */
const unsigned M = 15;           /* ���� ���������� �� �������� */
const unsigned N = 6;            /* ���� �������� */

void calculate(void) /* �������� ����������� �� �������� ������� */
{ unsigned i,j;
  for (j = 0; j <= M; j++)
	F[0][j] = 0;
  for (i = 1; i <= N; i++)
    for (j = 0; j <= M; j++)
      if (j >= m[i] && F[i-1][j] < F[i-1][j-m[i]] + c[i])
          F[i][j] = F[i-1][j-m[i]] + c[i];
        else
          F[i][j] = F[i-1][j];
}

void printTable(void) /* ������� ������������ �� ��������� F[i][j] */
{ unsigned i, j;
  for (i = 1; i <= N; i++) {
    printf("\n");
    for (j = 0; j <= M; j++)
      printf("%4u",F[i][j]);
  }
}

void printSet(void) /* ������� ���� �������� ��������� �� ��������, �� ����� */
{               /* �� ������� ���������� �������� �� �������� ������� */
   unsigned i = N,
            j = M;
   while (j != 0) {
     if (F[i][j] == F[i-1][j])
       i--;
     else {
       printf("%u ",i);
       j -= m[i];
       i--;
     }
   }
}

int main(void)
{ printf("%s%u","\n���� ��������: ",N);
  printf("%s%u","\n���������� ��������� ���� �����: ",M);
  calculate();
  printf("\n������� F[i][j]: ");
  printTable();
  printf("\n%s%u","���������� ���������� ��������: ",F[N][M]);
  printf("\n������� ���������� � ������: "); printSet();
  return 0;
}
