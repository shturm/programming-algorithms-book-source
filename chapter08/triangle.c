#include <stdio.h>
#define MAX   100
#define MAX2  MAX * (MAX + 1) / 2
#define INFINITY (unsigned)(-1)

unsigned p[MAX2];         /* ��������� ���� �� ��������� �� ����� I */
unsigned pred[MAX2];      /* ������������� �� ����� I � ���. ��� */

/* ���� �� ����������� ���� ��������� */
const unsigned v[MAX2] = {0,1,22,33,5,6,77,8,22,7,225,177,738,737,778,39,28,9,10,11,12,13};
const unsigned n = 6;             /* ���� ������ � ����������� */

void compare(unsigned ind1, unsigned ind2)
{ if (p[ind1] > p[ind2] + v[ind1]) {
    p[ind1] = p[ind2] + v[ind1];
    pred[ind1] = ind2;
  }
}

/* ������ ���������� ��� �� ����� ����� */
void findMinPath(void)
{ unsigned i, j, sum;
  /* �� ������ ���� �� ����� �������������� */
  for (p[1] = v[1], sum = 0, i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      if (j > 1)
		compare(sum + j + i - 1, sum + j);
      compare(sum + j + i, sum + j);
      compare(sum + j + i + 1, sum + j);
    }
    sum += i;
  }
}

/* ������� ����������� �� ����������� ������ �� ������ */
void print(const unsigned m[])
{ unsigned i, j, sum;
  for (sum = 0, i = 1; i <= n; printf("\n"), sum += i++)
    for (j = 1; j <= i; j++)
	  printf("%8u", m[sum + j]);
}

/* ������� ���������� ��� �� ����� x */
void writePath(unsigned x)
{ printf("\n%s%u%s%u", "����� �� ���� ����� ", x, " � ���������: ", p[x]);
  printf("\n�����, ������� � ������� ��� (�������): ");
  while (x != 1) {
    printf("%u ", x);
    x = pred[x];
  }
  printf("1");
}

/* ������ ���� �� ��������� ��� � ��������� ��� */
void findMinLastRow(void)
{ unsigned i, minInd, end = n * (n + 1) / 2;
  for (i = 1 + (minInd = end-n+1); i <= end; i++)
    if (p[i] < p[minInd])
	  minInd = i;
  writePath(minInd);
}

int main(void) {
  unsigned i;
  for (i = 0; i < (n + 3)*(n + 2)/2; i++)
	p[i] = INFINITY;
  printf("������� ����������:\n"); print(v);
  findMinPath();
  printf("\n���������� �� ����������� ������:\n"); print(p);
  findMinLastRow();
  return 0;
}