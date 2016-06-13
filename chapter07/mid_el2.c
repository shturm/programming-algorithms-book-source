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

unsigned partition(unsigned l, unsigned r) /* ��������� �� ������ */
{ int i;
  unsigned j;
  int x;
  i = l - 1; x = m[r];
  for (j = l; j <= r; j++)
    if (m[j] <= x) {
      i++;
      swap(m+i,m+j);
    }
  if (i == (int)r) /* ������ �������� �� <= x. ���������� �� �������� � 1. */
    i--;
  return i;
}

unsigned find(int l, int r, unsigned k) /* ������� �� k-�� ������� �� ���� */
{ unsigned mid, p;
  if (l == r)
    return l;
  mid = partition(l,r);
  p = mid - l + 1;
  return k < p ? find(l,mid,k) : find(mid+1,r,k-p);
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
  printf("\n������� ���� ���������:"); print(m,n);
  printf("\nk-��� ������� �: %d", m[find(0,n-1,k)]);
  return 0;
}