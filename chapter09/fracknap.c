#include <stdio.h>

#define MAXN 1000

const int n = 3;                       /* ���� �� ���������� */
const float c[MAXN] = { 25, 12, 16 };  /* ������������ �� ���������� */
const float m[MAXN] = { 10, 8, 8 };    /* ���������� �� ���������� */
const float M = 16;                    /* ������������� ����� �� �������� */

float ratio[MAXN];

void swap(float *a, float *b)
{ float s = *a; *a = *b; *b = s; }

/* ������� ���������� �� ������������ */
void sort(void)
{ int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (ratio[j] > ratio[i]) {
        swap(&c[i], &c[j]);
        swap(&m[i], &m[j]);
        swap(&ratio[i], &ratio[j]);
      }
}

/* ������ ��������� */
void solve(void)
{ int i = 0;
  float T = 0, V = 0;;
  while (T + m[i] <= M) {     /* ����� ���� ��������, ������ ���� */
    printf("������ 100%% �� ������� ��� �������� %.2f � ����� %.2f \n", c[i], m[i]);
    T += m[i]; V += c[i];
    i++;
  }
  printf("������ �� %.2f%% �� ������� ��� �������� %.2f � ����� %.2f \n",
                                       ((M - T) / m[i]) * 100, c[i], m[i]);
  V += (M - T) * (c[i] / m[i]);
  printf("���� �������� ����: %.2f\n", V);
}

int main(void) {
  int i;
  for (i = 0; i < n; i++) ratio[i] = c[i] / m[i];
  sort();
  solve();
  return 0;
}
