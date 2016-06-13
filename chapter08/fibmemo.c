#include <stdio.h>
#include <string.h>

#define MAX 256

const unsigned n = 10; /* ������ 10-���� ����� �� �������� */

unsigned long m[MAX + 1];

/* ���� ���������� ������ �������, ����������� ���� ������������� */
unsigned long fibMemo(unsigned n) 
{ if (n < 2)
    m[n] = n;
  else if (0 == m[n])
    m[n] = fibMemo(n - 1) + fibMemo(n - 2);
  return m[n];
}

int main(void) {
  memset(m, 0, MAX * sizeof(*m));
  printf("\n%u-���� ����� �� �������� �: %lu", n, fibMemo(n));
  return 0;
}
