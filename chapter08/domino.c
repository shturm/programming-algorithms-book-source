#include <stdio.h>
#define MAX 100
#define BASE 10 /* ������ �� �������� ������� */
unsigned succ[MAX];  /* ���������� �� ����� ���� */
unsigned F[BASE];    /* F[i]: ������ ����. ������� �� ��������� � ���-������ ����� i */
unsigned ind[BASE];  /* ind[i]: ������ �� ������ ���� �� �������� � ����� ����� i */

const unsigned n = 17;  /* ���� �������� � �������� */
const unsigned x[MAX] = {0, 72, 121, 1445, 178, 123, 3462, 762, 33434, 444,
                         472, 4, 272, 4657, 7243, 7326, 3432, 3465};              /* ������ */

/* ������ ���������� ������-������ */
void solve(void)
{ unsigned i, l, r;
  
  for (i = 0; i < BASE; i++)
	F[i] = ind[i] = 0;

  /* �������� ��������� �� ��������, ��������� � ����� �� ������� �� 0 �� 9 */
  for (i = n; i > 0; i--) {
    /* ���������� �� ���-�������� � ���-�������� ����� �� ������� */
    r = x[i] % BASE;
    l = x[i];
    while (l > BASE)
	   l /= BASE;
    /* ���������� ������������� �� ��������, ��������� ��� �������� ����� */
    if (F[r] >= F[l]) {
      F[l] = F[r] + 1;
      succ[i] = ind[r];
      ind[l] = i;
    }
  }
}

void print(void)
{ unsigned i, bestInd;

  /* ���������� �� ���-������� ������ */
  bestInd = 0;
  for (i = 1; i < BASE; i++) /* ����� ����� �� ������� � 0 */
    if (F[i] > F[bestInd])
	  bestInd = i;

  /* ��������� �� �������� �� ������ */
  printf("\n������� �� ������������ ������-���������: %u", F[bestInd]);
  printf("\n��� � ������ ���������: ");
  i = ind[bestInd];
  do {
    printf("%u ", x[i]);
    i = succ[i];
  } while (i > 0);
}

int main(void) {
  solve();
  print();
  return 0;
}