#include <stdio.h>
#define  MAXN 30     /* ���������� ���� �������� */
#define  MAXM 1000   /* ���������� ���������� �� �������� */

unsigned F[MAXM];    /* ������ ������� */
unsigned best[MAXM]; /* �������� ������� ������� ��� ��������� �� ��������� */

const unsigned m[MAXN] = {0,30,15,50,10,20,40,5,65}; /* ����� �� ���������� */
const unsigned c[MAXN] = {0,5,3,9,1,2,7,1,12};       /* �������� �� ���������� */
const unsigned M = 70;           /* ���� ���������� �� �������� */
const unsigned N = 8;            /* ���� �������� */

char used(unsigned i, unsign/ed j)
{ /* ��������� ���� j ������� � ����������� ���������, ���������� �� F[i] */
   while (i != 0 && best[i] != 0)
     if (best[i] == j)
		return 1;
     else
		i -= m[best[i]];
   return 0;
}

void calculate() /* �������� ����������� �� �������� ������� */
{ unsigned i,j;
 
  /* ������������� */
  for (i = 0; i <= M; i++)
	 best[i] = 0; 

  /* ������� ����� */
  for (i = 1; i <= M; i++)              
    for (j = 1; j <= N; j++)
      if (i >= m[j])
        if (F[i] < F[i-m[j]] + c[j])
          if (!used(i-m[j],j)) {
            F[i] = F[i-m[j]] + c[j];
            best[i] = j;
          }
}

void printSet() /* ������� ���� �������� ��������� �� ��������, �� ����� */
{               /* �� ������� ���������� �������� �� �������� ������� */
   unsigned value = M;
   while (value) {
     printf("%4u ",best[value]);
     value -= m[best[value]];
   }
}

int main() {
   printf("\n���� ��������: %u",N);
   printf("\n���������� ��������� ���� ����: %u",M);
   calculate();
   printf("\n���������� ���������� �������: %u",F[M]);
   printf("\n������� �������� ��������: "); printSet();
   return 0;
}
