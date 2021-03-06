#include <assert.h>
#include <stdio.h>

#define MAX 100

struct CElem {
  int data;
  /* ... */
} m[MAX];

const unsigned n = 10; /* ���� �������� � ������ */
const unsigned k = 2;  /* ���� �������� �� ���������� */

void init(void)
{ unsigned i;
  for (i = 0; i < n; i++)
    m[i].data = i;
}

void reverse(unsigned a, unsigned b)  /* ������ ��������� m[a..b] */
{ unsigned i, j, k, cnt;
  struct CElem tmp;
  for (cnt = (b - a) / 2, k = a, j = b, i = 0; i <= cnt; i++, j--, k++) {
    tmp = m[k];
    m[k] = m[j];
    m[j] = tmp;
  }
}

void shiftLeft3(unsigned k)
{ /* �������� ������ m �� k ������� ������, �� ��� ������ */
  reverse(0, k - 1);
  reverse(k, n - 1);
  reverse(0, n - 1);
}

void print(void)
{ unsigned i;
  for (i = 0; i < n; i++)
    printf("%d ", m[i].data);
  printf("\n");
}

int main(void) {
  init();
  shiftLeft3(k);
  print();
  return 0;
}