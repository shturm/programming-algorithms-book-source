#include <stdio.h>
#include <stdlib.h>

const unsigned n = 127; /* ��������� �� ���� �������� ����� n � ������ */
const unsigned k = 10;  /* ���� ����� �� ����� ����� ���������� ��� �������� ���� a */

/* �������� a^t mod n; */
unsigned long bigmod(unsigned long a, unsigned long t, unsigned long n)
{ return (t == 1) ? (a % n) : (bigmod(a, t - 1, n) * (a % n)) % n;
}

char strongRandom(unsigned long n, unsigned long a)
{ unsigned long s = 1, t = n - 1, x, i;

  /* ������ ������ */
  if (n < 2) return 0;
  if (n == 2) return 1;

  /* ������ 1) */
  while (t % 2 != 1) {
    s++;
    t /= 2;
  }
  /* ������ 2) x = a^t mod n; */
  x = bigmod(a, t, n);
  if (1 == x) return 1;
  /* ������ 3 */
  for (i = 0; i < s; i++) {
    if (x == n - 1) return 1;
    x = x * x % n;
  }
  return 0;
}

char isPrime(unsigned long n)
{ unsigned i;
  for (i = 1; i <= k; i++) {
    long int a = random(n - 3) + 2;
    if (!strongRandom(n, a)) return 0;
  }
  return 1;
}

int main(void) {
  printf("������� %d e %s.\n", n, (isPrime(n)) ? "������" : "��������");
  return 0;
}
