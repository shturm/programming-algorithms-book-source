#include <stdio.h>
#include <math.h>

const unsigned n = 23;

/* ��������� ����� 1 ��� n � ������ � 0 ��� n � �������� */
char isPrime(unsigned n)
{ unsigned i = 2;
  if (n == 2) return 1;
  while (i <= sqrt(n)) {
    if (n % i == 0) return 0;
    i++;
  }
  return 1;
}

int main(void) {
  if (isPrime(n))
    printf("������� %u � ������.\n", n);
  else
    printf("������� %u � ��������.\n", n);
}
