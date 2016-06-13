#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int m[MAX];

const unsigned n = 100; /* ���� �������� � ������ */
const unsigned k = 10;  /* ������� ����� �� �������� ������� */

void init(int m[], unsigned n) /* ������� ������ ��� �������� ����� */
{ unsigned i;
  for (i = 0; i < n; i++)
    m[i] = rand() % (2*n + 1);
}

void siftMin(int l, int r) /* �������� �� �������� �� ����� �� ���������� */
{ int i,j;
  int x;
  i = l; j = i + i + 1; x = m[i];
  while (j <= r) {
    if (j < r)
      if (m[j] > m[j+1])
        j++;
    if (x <= m[j])
      break;
    m[i] = m[j];
    i = j;
    j = j*2 + 1;
  }
  m[i] = x;
}

void siftMax(int l, int r) /* �������� �� �������� �� ����� �� ���������� */
{ int i,j;
  int x;
  i = l; j = i + i + 1; x = m[i];
  while (j <= r) {
    if (j < r)
      if (m[j] < m[j+1])
        j++;
    if (x >= m[j])
      break;
    m[i] = m[j];
    i = j;
    j = j*2 + 1;
  }
  m[i] = x;
}

void heapFindK(unsigned k) /* ������� �� k-�� ������� � �������� */
{ int l,r;
  char useMax;
  if (useMax = (k > n/2))
    k = n - k - 1;
  l = n/2; r = n - 1;
  /* ����������� �� ���������� */
  while (l-- > 0)
    if (useMax) siftMax(l,r); else siftMin(l,r);
  /* (k-1)-������ ���������� �� ���������� ������� */
  for (r = (int)n-1; r >= (int)(n-k); r--) {
    m[0] = m[r];
    if (useMax) siftMax(0,r); else siftMin(0,r);
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
  heapFindK(k);
  printf("\nk-��� ������� �: %d", m[0]);
  return 0;
}