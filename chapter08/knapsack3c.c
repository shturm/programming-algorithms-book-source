#include <stdio.h>
#define MAXN            30    /* ���������� ���� �������� */
#define MAXM            1000  /* ���������� ���������� �� �������� */

const unsigned m[MAXN] = {0,1,2,3,5,6,7};      /* ����� �� ���������� */
const unsigned c[MAXN] = {0,1,10,19,22,25,30}; /* �������� �� ���������� */
const unsigned M = 15;              /* ���� ���������� �� �������� */
const unsigned N = 6;               /* ���� �������� */

unsigned calculate(void) /* �������� ����������� �� �������� ������� */
{ unsigned F[MAXM], OldF[MAXM]; /* ������ ������� */
  unsigned i,j,k;

  for (j = 0; j <= M; j++)
	OldF[j] = 0;
  for (i = 1; i <= N; i++) {
     for (j = 0; j <= M; j++)
        if (j >= m[i] && OldF[j] < OldF[j-m[i]] + c[i])
           F[j] = OldF[j-m[i]] + c[i];
        else F[j] = OldF[j];
     for (k = 0; k < M; k++)
        OldF[k] = F[k];
  }
  return F[M];
}

int main(void) {
   printf("%s%u","\n���� ��������: ",N);
   printf("%s%u","\n���������� ��������� ���� ����: ",M);
   printf("\n%s%u","���������� ���������� �������: ",calculate());
   return 0;
}