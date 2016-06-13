#include <stdio.h>
#define  MAXN 30           /* ���������� ���� �������� */
#define  MAXM 1000         /* ���������� ���������� �� �������� */

unsigned F[MAXN][MAXM];    /* ������ ������� */

const unsigned m[MAXN] = {0,6,3,10,2,4,8,1,13,3};  /* ����� �� ���������� */
const unsigned c[MAXN] = {0,5,3,9,1,2,7,1,12,3};   /* ���� �� ���������� */
const unsigned M = 14;           /* ���� ���������� �� �������� */
const unsigned N = 9;            /* ���� �������� */

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

unsigned set[MAXN]; /* ��������� �� ��������, �� ����� �� ������� max */

void printAll(unsigned i, unsigned j, unsigned k)
{   /* ������� ������ �������� ��������� �� ��������, �� ����� */
    /* �� ������� ���������� �������� �� �������� ������� */
   if (0 == j) {
     printf("\n������� �������� ��������: ");
     for (i = 0; i < k; i++)
       printf("%u ",set[i]);
   }
   else {
     if (F[i][j] == F[i-1][j])
       printAll(i-1,j,k);
     if (j >= m[i] && F[i][j] == F[i-1][j-m[i]] + c[i]) {
       set[k] = i;
       printAll(i-1,j-m[i],k+1);
     }
   }
}

int main(void) {
   printf("%s%u","\n���� ��������: ",N);
   printf("%s%u","\n���������� ��������� ���� ����: ",M);
   calculate();
   printf("\n������� F[i][j]: ");
   printTable();
   printf("\n%s%u","���������� ���������� ��������: ",F[N][M]);
   printf("\n������� ������������� ��������� �� �������:");
   printAll(N,M,0);
   return 0;
}
