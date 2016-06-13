#include <stdio.h>
#define MAXCOINS  100 /* ���������� ���� ������ */
#define MAXSUM    100 /* ���������� ���� */

unsigned long F[MAXSUM][MAXSUM];    /* ������ ������� */
unsigned char exist[MAXSUM];        /* ���������� �� ������ � ������ �������� */

const unsigned coins[MAXCOINS] = {1,2,3,4,6}; /* ������� ������ ������ */
const unsigned sum = 6;                       /* ����, ����� ������ �� ������� */
const unsigned n = 5;                         /* ��� ���� ������� ������ */

/* �������������� ������� */
void init(void)
{ unsigned i, j;
  /* �������� �� �������� ������� */
  for (i = 0; i <= sum; i++)
    for (j = 0; j <= sum; j++)
	   F[i][j] = 0;
  /* ����� ����������� �� ����������� �� �������� �� ��-���� ������ */
  for (i = 0; i <= sum; i++)
	 exist[i] = 0;
  for (i = 0; i < n; i++)
	 exist[coins[i]] = 1;
}

/* ������ ���� �� �������������� �� sum */
unsigned long count(unsigned sum, unsigned max)
{ unsigned long i;
  if (sum <= 0)
	return 0;
  if (F[sum][max] > 0)
    return F[sum][max];
  else {
    if (sum < max)
	   max = sum;
    if (sum == max && exist[sum])   /* ���������� ������ � ������ �������� */
      F[sum][max] = 1;
    for (i = max; i > 0; i--)  /* ���������� ������ */
      if (exist[i])
		 F[sum][max] += count(sum - i, i);
  }
  return F[sum][max];
}

int main(void) {
  init();
  printf("\n����� �� �������������� �� %u � ��������� ������ � %lu",
         sum, count(sum, sum));
  return 0;
}