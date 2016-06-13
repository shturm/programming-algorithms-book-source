#include <string.h>
#include <stdio.h>
#define NOT_CALCULATED  (unsigned) (-1)
#define MAXN            30    /* ���������� ���� �������� */
#define MAXM            1000  /* ���������� ���������� �� �������� */

char set[MAXM][MAXN / 8];       /* ��������� �� �������� �� ����� k=1..M */
unsigned Fn[MAXM];              /* ������ ������� */

const unsigned m[MAXN] = { 0, 30, 15, 50, 10, 20, 40, 5, 65 };  /* ����� �� ���������� */
const unsigned c[MAXN] = { 0, 5, 3, 9, 1, 2, 7, 1, 12 };        /* �������� �� ���������� */
const unsigned M = 70;          /* ���� ���������� �� �������� */
const unsigned N = 8;           /* ���� �������� */


void calculate(void)
{ unsigned maxValue;                  /* ���������� ���������� �������� */
  unsigned maxIndex;                  /* ������, �� ����� � ���������� */
  unsigned i, j;
  memset(set, 0, sizeof(set));        /* �������������� �� ����������� � �������� */

  /* ���������� ����������� �� �������� ������� */
  for (i = 1; i <= M; i++) { /* ������� �� ������������ �������� �� F(i) */
    maxValue = maxIndex = 0;
    for (j = 1; j <= N; j++) {
      if (m[j] <= i && !(set[i - m[j]][j >> 3] & (1 << (j & 7))))
        if (c[j] + Fn[i - m[j]] > maxValue) {
          maxValue = c[j] + Fn[i - m[j]];
          maxIndex = j;
        }
    }

    if (maxIndex > 0) {               /* ���������� �� ������� � �����, ��-����� �� i? */
      Fn[i] = maxValue;

      /* ������ ��������� set[i] �� �������� �� set[i-m[maxIndex]]
       * ���� ��������� �� �������� maxIndex
       */
      memcpy(set[i], set[i - m[maxIndex]], (N >> 3) + 1);
      set[i][maxIndex >> 3] |= 1 << (maxIndex & 7);
    }

    if (Fn[i] < Fn[i - 1]) {            /* �������� ������ ������ �������� � ���� ��� */
      Fn[i] = Fn[i - 1];
      memcpy(set[i], set[i - 1], (N >> 3) + 1);
    }
  }

  /* ��������� �� ��������� */
  printf("\n������� ���������� � ������:\n");
  for (i = 1; i <= N; i++)
    if (set[M][i >> 3] & (1 << (i & 7)))
	  printf("%5u", i);
  printf("\n%s%u", "���������� ���������� �������: ", Fn[M]);
}

int main(void) {
  printf("%s%u", "\n���� ��������: ", N);
  printf("%s%u", "\n���������� �� ��������: ", M);
  calculate();
  return 0;
}
