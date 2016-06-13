#include <assert.h>
#include <stdio.h>

#define MAX 100

struct CElem {
  int data;
  /* ... */
} m[MAX];

const unsigned n = 10; /* ���� �������� � ������ */
const unsigned k = 2;  /* ���� ������� �� ���������� */

void init(void)
{ unsigned i;
  for (i = 0; i < n; i++)
    m[i].data = i;
}

unsigned gcd(unsigned x, unsigned y)
{ while (y > 0) {
    unsigned tmp = y;
    y = x % y;
    x = tmp;
  }
  return x;
}

void shiftLeft1(unsigned k)
{ /* �������� ������ m �� k ������� ������, ���� �������� ������� ���������� */
  unsigned i, ths, next, gcdNK;
  struct CElem tmp;

  for (gcdNK = gcd(n, k), i = 0; i < gcdNK; i++) {
    ths = i; tmp = m[ths];
    next = ths + k;
    if (next >= n)
       next -= n;
    while (next != i) {
      m[ths] = m[next];
      ths = next;
      next += k;
      if (next >= n)
         next -= n;
    }
    m[ths] = tmp;
  }
}

void print(void)
{ unsigned i;
  for (i = 0; i < n; i++)
    printf("%d ", m[i].data);
  printf("\n");
}

int main(void) {
  init();
  shiftLeft1(k);
  print();
  return 0;
}