#include <stdio.h>

/* ���������� ���� ������ ���������� */
#define MAXN 100
/* ���������� ���� �������� */
#define MAXK 100

const unsigned n = 4;  /* ���� �� �������� ���������� */
const unsigned k = 5;  /* ���� �� ���������� */

const int expr[][MAXK] = {
  {  1,  4 },
  { -1,  2 },
  {  1, -3 },
  { -2,  3, -4 },
  { -1, -2, -3 }
};

int values[MAXN];

void printAssignment(void)
{ unsigned i;
  printf("������� � ������������ ��: ");
  for (i = 0; i < n; i++) printf("X%u=%u ", i+1, values[i]);
  printf("\n");
}

/* ��� ����� �� �-�� �������� ���� ���� ������� ������ �� ��� �������� �������� */
int true(void)
{ unsigned i;
  for (i = 0; i < k; i++) {
    unsigned j = 0;
    char ok = 0;
    while (expr[i][j] != 0) {
      int p = expr[i][j];
      if ((p > 0) && (1 == values[p-1])) { ok = 1; break; }
      if ((p < 0) && (0 == values[-p-1])) { ok = 1; break; }
      j++;
    }
    if (!ok) return 0;
  }
  return 1;
}

/* ��������� ��������� �� ������������ */
void assign(unsigned i)
{ if (i == n) {
    if (true()) printAssignment();
    return;
  }
  values[i] = 1;  assign(i + 1);
  values[i] = 0;  assign(i + 1);
}

int main(void) { 
  assign(0);
  return 0;
}
