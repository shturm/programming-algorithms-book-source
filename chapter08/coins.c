#include <stdio.h>
#define MAXCOINS  100       /* ���������� ���� ������ */
#define MAXSUMA   1000      /* ���������� ���� */

struct {
  unsigned num;             /* ���� ������ � ������ */
  unsigned last;            /* �������� �������� ������ */
} sums[MAXSUMA];            /* ������ ������� */

/* ��������� �� �������� */
const unsigned coins[MAXCOINS] = {0,5,2,2,3,2,2,2,4,3,5,8,6,7,9};
const unsigned sum = 31;    /* ����, ����� ����������� ������������ */
const unsigned n = 14;      /* ��� ���� ������� ������ */

/* ���� ����� �� ���������� j-���� ������ � i-���� ����? */
char canJ(unsigned i, unsigned j)
{ int k = i - coins[j];
  if (k > 0 && sums[k].num < MAXCOINS)
    while (k > 0) {
      if (sums[k].last == j) break; /* j-���� ������ ������� � ������ */
      k -= coins[sums[k].last];
    }
  return(0 == k);
}

/* ������ ����������� �� ������ Sum � ��������� ���� ������ */
void findMin(unsigned sum)
{ unsigned i, j;
  sums[0].num = 0;
  for (i = 1; i <= sum; i++) {
    sums[i].num = MAXCOINS;
    for (j = 1; j <= n; j++) {
      if (canJ(i, j))
        if ((sums[i - coins[j]].num + 1) < sums[i].num) {
          sums[i].num = 1 + sums[i - coins[j]].num;
          sums[i].last = j;
        }
    }
  }
}

void print(unsigned sum)
{ /* ������� ���������� ����������� */
  if (sums[sum].num == MAXCOINS)
    printf("\n������ �� ���� �� �� ������ � ��������� ������.");
  else {
    printf("\n��������� ���� ���������� ������: %u", sums[sum].num);
    printf("\n��� � ����������� �� ������ ������: ");
    while (sum > 0) {
      printf("%u ", coins[sums[sum].last]);
      sum -= coins[sums[sum].last];
    }
  }
}

int main(void) {
  printf("\n%s %u %s", "��� �� ������� ���� ��",
         sum,"���� � ��������� ���� ������?");
  findMin(sum);
  print(sum);
  return 0;
}