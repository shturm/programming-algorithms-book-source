#include <string.h>
#include <stdio.h>
#define NOT_CALCULATED  (unsigned) (-1)
#define MAXN            30    /* ���������� ���� �������� */
#define MAXM            1000  /* ���������� ���������� �� �������� */

char set[MAXM][MAXN];           /* ��������� �� �������� �� ����� k=1..M */
unsigned Fn[MAXM];              /* ������ ������� */

const unsigned m[MAXN] = { 0, 30, 15, 50, 10, 20, 40, 5, 65 };  /* ����� �� ���������� */
const unsigned c[MAXN] = { 0, 5, 3, 9, 1, 2, 7, 1, 12 };        /* �������� �� ���������� */
const unsigned M = 70;          /* ���� ���������� �� �������� */
const unsigned N = 8;           /* ���� �������� */

/* �������� ���������� �� ��������� �� k */
void F(unsigned k)
{ unsigned i, bestI, fnBest, fnCur;
  /* ���������� �� ���-�������� �������� �� F */
  for (bestI = fnBest = 0, i = 1; i <= N; i++) {
    if (k >= m[i]) {
      if (NOT_CALCULATED == Fn[k - m[i]]) F(k - m[i]);
      if (!set[k - m[i]][i])
        fnCur = c[i] + Fn[k - m[i]];
      else
        fnCur = 0;
      if (fnCur > fnBest) {
        bestI = i;
        fnBest = fnCur;
      }
    }
  }
  /* ����������� �� ���-�������� �������� �� ��������� */
  Fn[k] = fnBest;
  if (bestI > 0) {
    memcpy(set[k], set[k - m[bestI]], N);
    set[k][bestI] = 1;
  }
}

/* ���������� �� ���������� �� ��������� */
void calculate(void) {
  unsigned i, sumM;

  /* ������������� */
  memset(set, 0, sizeof(set));  /* �������������� �� ����������� � �������� */
  for (i = 0; i <= M; i++)      /* �������������� �� ����������� �� �������� ������� */
    Fn[i] = NOT_CALCULATED;

  /* ���� �� ����� �� ������ ������ ��������? */
  for (sumM = m[1], i = 2; i <= N; i++)
    sumM += m[i];
  if (M >= sumM) {
    printf("\n������ �� ������� ������ ��������!");
    return;
  }
  else {
    F(M); /* ���������� �� ���������� */

    /* ����������� �� ��������� */
    printf("\n������� ���������� � ������:\n");
    for (i = 1; i <= N; i++)
      if (set[M][i])
		printf("%5u", i);
    printf("\n���������� ���������� ��������: %u", Fn[M]);
  }
}

int main(void) {
  printf("%s%u", "\n���� ��������: ", N);
  printf("%s%u", "\n���������� �� ��������: ", M);
  calculate();
  return 0;
}
