#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int m[MAX];

const unsigned n = 100; /* ���� �������� � ������ */
const unsigned k = 10;  /* ������� ����� �� �������� ������� */

void init(int m[], unsigned n) /* ������� ������ ��� �������� ����� */
{ unsigned i;
  for (i = 0; i < n; i++)
    m[i] = rand() % (2*n+1);
}

void swap(int *el1, int *el2) /* ������� ����������� �� ��� ���������� */
{ int tmp = *el1; *el1 = *el2; *el2 = tmp; }

void find(int m[], unsigned n, unsigned k) /* ������ k-�� ������� */
{ int i,j,l,r;
  int x;
  l = 0; r = n - 1;
  while (l < r) {
    x = m[k]; i = l; j = r;
    for(;;) {
      while (x > m[i]) i++;
      while (x < m[j]) j--;
      if (i > j)
        break;
      swap(m + i, m + j);
      i++;
      j--;
    }
    if (j < (int)k)
      l = i;
    if ((int)k < i)
      r = j;
  }
}

void print(int m[], unsigned n) /* ������� ������ �� ������ */
{ unsigned i;
  for (i = 0; i < n; i++)
    printf("%8d", m[i]);
}

int main(void) {
  init(m,n);
  printf("������� ����� ���������:"); print(m,n);
  printf("\n������ k-�� �������: k=%u", k);
  find(m,n,k);
  printf("\n������� ���� ���������:"); print(m,n);
  printf("\nk-��� ������� �: %d", m[k]);
  return 0;
}