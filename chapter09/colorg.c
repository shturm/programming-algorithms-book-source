#include <stdio.h>

#define MAXN 200

const int n = 6;
const char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 1 },
  { 0, 1, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 1 },
  { 0, 0, 1, 0, 0, 0 },
  { 0, 1, 0, 1, 0, 0 }
};

int color[MAXN];

/* ��������� �� ���������� � ����������, � �� �������� �� �������� �� ��� */
void solve1(void)
{ int flag, i, j;
  for (i = 0; i < n; i++) { /* �������� i-��� ���� � ���-������� �������� ���� */
    int c = 0;
    do {
      c++;
      flag = 1;
      for (j = 0; j < n; j++)
        if (A[i][j] && color[j] == c) {
          flag = 0;
          break;
        }
    } while (!flag);
    color[i] = c;
  }
}

void solve2(void)
{ int c = 0, cn = 0, i, j;
  /* �������� ������� ���� � ������ ����, ������ � ��������, ���� ���� ���� �
   * ������ � �.�., ������ ������ ������� ����� ��������
   */
  while (cn < n) {
    c++;
    for (i = 0; i < n; i++) {
      if (!color[i]) {
        int flag = 1;
        for (j = 0; j < n; j++)
          if (A[i][j] && color[j] == c) {
            flag = 0;
            break;
          }

        if (flag) {
          color[i] = c;
          cn++;
        }
      }
    }
  }
}

void showColor(void)
{ int i;
  for (i = 0; i < n; i++) printf("%d-%d; ", i + 1, color[i]);
  printf("\n");
}

int main(void) {
  int i;
  printf("���������� �� ��������� �� ��������� 1: \n");
  for (i = 0; i < n; i++) color[i] = 0;
  solve1();
  showColor();
  printf("���������� �� ��������� �� ��������� 2: \n");
  for (i = 0; i < n; i++) color[i] = 0;
  solve2();
  showColor();
  return 0;
}
