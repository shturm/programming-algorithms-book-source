#include <stdio.h>
#define  MAXN 30     /* ���������� ���� �������� */
#define  MAXM 1000   /* ���������� ���������� �� �������� */

unsigned F[MAXM];    /* ������ ������� */
unsigned best[MAXM]; /* �������� ������� ������� ��� ��������� �� ��������� */

const unsigned m[MAXN] = {0,30,15,50,10,20,40,5,65}; /* ����� �� ���������� */
const unsigned c[MAXN] = {0,5,3,9,1,2,7,1,12};       /* �������� �� ���������� */
const unsigned M = 70;           /* ���� ���������� �� �������� */
const unsigned N = 8;            /* ���� �������� */

void calculate(void) /* �������� ����������� �� �������� ������� */
{ unsigned i,j;

  /* ������������� */
  for (i = 0; i <= M; i++)
	 F[i] = 0; 

  /* ������� ����� */
  for (j = 1; j <= N; j++)
    for (i = 1; i <= M; i++)
      if (i >= m[j])
        if (F[i] < F[i-m[j]] + c[j]) {
          F[i] = F[i-m[j]] + c[j];
          best[i] = j;
        }
}

void printSet(void)  /* ������� ���� �������� ��������� �� ��������, �� ����� */
{                    /* �� ������� ���������� �������� �� �������� ������� */
   unsigned value = M;
   printf("\n������� �������� ��������: ");
   while (value) {
     printf("%4u ", best[value]);
     value -= m[best[value]];
   }
}

int main(void) {
   printf("%s%u","\n���� ��������: ",N);
   printf("%s%u","\n���������� ��������� ���� ����: ",M);
   calculate();
   printf("\n%s%u","���������� ���������� ��������: ",F[M]);
   printSet();
   return 0;
}