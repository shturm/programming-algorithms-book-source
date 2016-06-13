#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 150

/* ���� ������� � ����� */
const unsigned n = 6;
/* ������� �� ������� �� ����� */
int A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 1, 0 },
  { 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0 }
};

const MAX_VALUE = 10000;

/* ������ ��������� �� ���������� ��� ����� ����� ������ ������� */
void floyd(void)
{ unsigned i, j, k;
  /* ����������� 0 �� �������� �� MAX_VALUE */
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (A[i][j] == 0) A[i][j] = MAX_VALUE;
  /* ��������� �� ����� */
  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (A[i][j] > (A[i][k] + A[k][j]))
          A[i][j] = A[i][k] + A[k][j];

  for (i = 0; i < n; i++) A[i][i] = 0;
}

void findCenter(void)
{ unsigned i, j, min, max, center;
  min = MAX_VALUE;
  /* Sot(Xi) = max { Vj [d(Xi, Xj)+d[Xj,Xi])] }, Xj � V �������� � ���� ���� X* ��
   * ����� Sot(X*) � ���������
   */
  for (i = 0; i < n; i++) {
    max = A[i][0] + A[0][i];
    for (j = 0; j < n; j++)
      if ((i != j) && ((A[i][j] + A[j][i]) > max)) max = (A[i][j] + A[j][i]);
    if (max < min) {
      min = max; center = i;
    }
  }
  printf("�������� �� ����� � ���� %u\n", center + 1);
  printf("�������� �� ����� � %u\n", min);
}

int main(void) {
  floyd();
  findCenter();
  return 0;
}
