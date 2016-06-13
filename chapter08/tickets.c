#include <stdio.h>
#define MAXN      1000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

unsigned F[MAXN]; /* ������ ������� */

const unsigned T[MAXN] = {8,5,3,9,2,1,4,4,1,17}; /* ����� �� ���������� �� ���� ��� */
const unsigned R[MAXN] = {1,3,9,4,2,4,9,3,8}; /* ����� �� ���������� �� ������ ������ */
unsigned n = 10; /* ���� ������ */

/* �������� ����������� �� �������� ������� */
void solve(void)
{ unsigned i;
  F[0] = 0; F[1] = T[0];
  for (i = 2; i <= n; i++)
    F[i] = MIN(F[i - 1] + T[i - 1], F[i - 2] + R[i - 2]);
}

/* ������� ��������� �� ������ */
void print(void)
{ printf("\n��������� ����� �� ���������� �� ��������: %u", F[n]);
  do
    if (F[n - 1] + T[n - 1] == F[n])
      printf("\n%u", n--);
    else {
      printf("\n(%u,%u)", n - 1, n);
      n -= 2;
    }
  while (n > 0);
}

int main(void) {
  solve();
  print();
  return 0;
}