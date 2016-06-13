#include <stdio.h>
#include <stdlib.h>
#define MAX  100

int a[MAX],          /* ������� ����� - �� ��������� */
    b[MAX];          /* ������� ����� */

const unsigned n = 100; /* ���� �������� �� ��������� */

/* �������� �������� ��������� */
void generate(void)
{ unsigned i;
  for (i = 0; i < n; i++)
	a[i] = rand() % (2*n + 1);
}

/* ������� ������� �� ������ */
void printList(void)
{ unsigned i;
  for (i = 0; i < n; i++)
	printf("%4d", a[i]);
}

/* ��������� */
void mergeSort(unsigned left, unsigned right)
{ unsigned i, j, k, mid;
  if (right <= left) return;  /* �������� ���� ��� ����� �� �� ������� */
  mid = (right + left) / 2;
  mergeSort(left, mid);       /* ��������� �� ����� ��� */
  mergeSort(mid + 1, right);  /* ��������� �� ������ ��� */

  /* �������� �� ���������� �� a[] � �������� ����� b[] */
  for (i = mid + 1; i > left; i--)
	b[i - 1] = a[i - 1];           /* ����� ������ */
  for (j = mid; j < right; j++)
	b[right + mid - j] = a[j + 1]; /* ������� ������ */

  /* ������� �� ����� ������ � a[] */
  for (k = left; k <= right; k++)
	a[k] = (b[i] < b[j]) ? b[i++] : b[j--];
}

int main(void) {
  generate();
  printf("����� �����������:\n");
  printList();
  mergeSort(0, n-1);
  printf("���� �����������:\n");
  printList();
  return 0;
}