#include <stdio.h>
#define MAXCOINS    100 /* ���������� ���� ������ */
#define MAXSUM      100 /* ���������� ���� */
#define SWAP(a, b)  { a = a ^ b; b = a ^ b; a = a ^ b; }

unsigned long F[MAXSUM][MAXSUM]; /* ������ ������� */

const unsigned n = 7;   /* ��� ���� ������� ������ */
const unsigned sum = 6; /* ����, ����� ������ �� ������� */
unsigned coins[MAXCOINS] = {1,2,2,3,3,4,6}; /* ������� ������ ������ */

/* �������������� ������� */
void init(void)
{ unsigned i, j;
  /* �������� �� �������� ������� */
  for (i = 0; i <= sum; i++)
    for (j = 0; j <= sum; j++)
	  F[i][j] = 0;
}

/* ������� �������� � ��������� ��� */
void sort(void)
{ unsigned i, j;
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (coins[i] > coins[j])
		 SWAP(coins[i], coins[j]);
}

/* ������ ���� �� �������������� �� sum ��� ���������� �� ������� k ������ */
unsigned long count(int sum, int k)
{ unsigned j;
  if (sum <= 0 || k < 0)
	 return 0;
  if (F[sum][k] > 0)
    return F[sum][k];
  else {
    if (coins[k] == (unsigned)sum)
	  F[sum][k] = 1;
    F[sum][k] += count(sum - coins[k], k - 1);
    j = k;
    while (coins[j] == coins[k]) j--;
    F[sum][k] += count(sum, j);
  }
  return F[sum][k];
}

int main(void) {
  init();
  sort();
  printf("\n����� �� �������������� �� %u � ��������� ������ � %lu.",
         sum, count(sum, n - 1));
  return 0;
}