#include <stdio.h>
#include <string.h>
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MAXPERCITY  100                    /* ���������� ���������� ����� �� ���� */
#define MAXCITIES   50                     /* ���������� ���� ������� �� �������� */
#define MAXCARGO    200                    /* ������. ���������� ����� �� ������������ */
#define INFINITY    (unsigned)(-1)


unsigned F[MAXCITIES][MAXCARGO];           /* ������ ������� */
unsigned amount[MAXCITIES][MAXCARGO];      /* ��������� ���������� ����� */
unsigned inc;

unsigned k = 3;                            /* ���� ������� �� ������������ �� ������� */
unsigned n = 5;                            /* ������������ ����� �� ������������ */
const unsigned M = 5;                      /* ������.���������� �� ��������� � ���� */
const unsigned v[MAXCITIES][MAXPERCITY] = {/* ������� �� ������ �� ������� */
  { 0, 10, 15, 25, 40, 60 },
  { 0, 15, 20, 30, 45, 60 },
  { 0, 20, 30, 40, 50, 60 }
};


unsigned maxIncome(unsigned city, unsigned ccargo)
{ unsigned i, max;
  if (0 == ccargo)
    return 0;               /* ��� ���� �����, ���� � ������� ;) */
  else if (0 == city) {
    /* ��� �����.����� ccargo ������ �� �� ���������� ���� */
    /* �� 1 ����, �� ������ ������.������� �� ���� ���� �� ���� ����� */
    for (i = max = 0; i <= MIN(ccargo, M); i++)
      if (max < v[city][i]) {
        max = v[city][i];
        amount[city][ccargo] = i;
      }
    F[city][ccargo] = max;
    return max;
  }
  else if (F[city][ccargo] != INFINITY) /* ��� �����. � ���� ���������, */
    return F[city][ccargo];             /* �� ����� ���������� � �� ��������� */
  else {
    /* ����� �� ����.����, �������� �� �����. i ����� � ���� ���� ���� */
    /* ������������ �������� ����� ccargo-i � ���������� ������� */
    for (i = max = 0; i <= MIN(ccargo, M); i++) {
      inc = v[city][i] + maxIncome(city - 1, ccargo - i);
      if (max < inc) {
        max = inc;
        amount[city][ccargo] = i;
      }
    }
    F[city][ccargo] = max;
    return max;
  }
}

void scheduleCargo(void)
{ unsigned i,j;
  for (i = 0; i <= k; i++)
    for (j = 0; j <= n; j++)
	  F[i][j] = INFINITY;
  F[k - 1][n] = maxIncome(k - 1, n);
}

void printResults(void)
{ printf("\n���������� �����: %u", F[--k][n]);
  for(;;) {
    if (0 == n)
      printf("\n� ���� %u �������� ���������� 0.", k+1);
    else {
      printf("\n� ���� %u �������� ���������� %u.", k+1, amount[k][n]);
      n -= amount[k][n];
    }
	if (0 == k--)
	  break;
  }
  if (n > 0)
	printf("\n������ �����: %u", n);
}

int main(void)
{ scheduleCargo();
  printResults();
  return 0;
}