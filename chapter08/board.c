#include <stdio.h>
#define MAX 1000

unsigned F[MAX];                               /* ������ ������� */
unsigned next[MAX];                            /* ������� ��������� */

const unsigned n = 9;                          /* ���� ���������� */
const unsigned p[MAX] = {0,9,1,3,6,2,7,5,4,8}; /* ������� ���������� */

void solve(void)
{ unsigned k, i;
  /* ������������� */
  for (i = 1; i <= n; i++) {
    F[i] = 1;
    next[i] = 0;
  }
  /* ������� ����� */
  for (k = n; k >= 1; k--)
    for (i = k + 1; i <= n; i++)
      if (p[k] < p[i])
        if (1 + F[i] > F[k]) {
          F[k] = 1 + F[i];
          next[k] = i;
        }
}

/* ������� ��������� �� ������ */
void print(void)
{ unsigned i, max, index;
  for (max = F[index = 1], i = 2; i <= n; i++)
    if (F[i] > max) {
      max = F[i];
      index = i;
    }
  printf("\n���������� ���� ������: %u\n", max);
  do {
    printf("%u ", index);
    index = next[index];
  } while (index);
}

int main(void) {
  solve();
  print();
  return 0;
}