#include <stdio.h>

const unsigned n = 23;

/* ���� ������ �����, � ����� ����������� � ��������� ������������� */
#define K 25
unsigned prime[K] = {
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
  47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

/* ����������� ���� ����� � ������, ���� ����������� ���� ��� �������� ����
 * ������� �� ������ prime[]
 */
char checkprime(unsigned n)
{ unsigned i = 0;
  while (i < K && prime[i] * prime[i] <= n) {
    if (n % prime[i] == 0) return 0;
    i++;
  }
  return 1;
}

int main(void)
{ if (checkprime(n))
    printf("������� %u � ������. \n", n);
  else
    printf("������� %u � ��������. \n", n);
  return 0;
}
