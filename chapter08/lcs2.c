#include <stdio.h>
#include <string.h>
#define MAX     100
#define LEFT    1
#define UP      2
#define UPLEFT  3

char F[MAX][MAX];                     /* ������ ������� */
char b[MAX][MAX];                     /* �������� ��� ��������� ������� */

const char x[MAX] = "acbcacbcaba";    /* ����� ������ */
const char y[MAX] = "abacacacababa";  /* ����� ������ */

/* ������ ��������� �� ���-������� ���� ��������� */
unsigned LCS_Length(void)
{ unsigned i, j, m, n;
  m = strlen(x);  /* ������� �� ������� ������ */
  n = strlen(y);  /* ������� �� ������� ������ */
  /* ������� ������������� */
  for (i = 1; i <= m; i++)
	F[i][0] = 0;
  for (j = 0; j <= n; j++)
	F[0][j] = 0;
  /* ������� ����� */
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (x[i - 1] == y[j - 1]) {
        F[i][j] = F[i - 1][j - 1] + 1;
        b[i][j] = UPLEFT;
      }
      else if (F[i - 1][j] >= F[i][j - 1]) {
        F[i][j] = F[i - 1][j];
		b[i][j] = UP;
      }
      else {
        F[i][j] = F[i][j - 1];
		b[i][j] = LEFT;
      }
    }
  }
  return F[m][n];
}

/* ������ ���� �������� ���������� ���� ��������� (��������) */
void printLCS(void) {
  unsigned i = strlen(x),
           j = strlen(y);
  while (i > 0 && j > 0)
    switch (b[i][j]) {
      case UPLEFT:  printf("%c", x[i - 1]); i--; j--; break;
      case UP:      i--; break;
      case LEFT:    j--;
    }
}

/* ������ ���� �������� ���������� ���� ��������� */
void printLCS2(unsigned i, unsigned j)
{ if (0 == i || 0 == j)
    return;
  if (UPLEFT == b[i][j]) {
    printLCS2(i - 1, j - 1);
    printf("%c", x[i - 1]);
  }
  else if (UP == b[i][j])
    printLCS2(i - 1, j);
  else
    printLCS2(i, j - 1);
}

/* ������ ���� �������� ���������� ���� ��������� */
void printLCS3(unsigned i, unsigned j)
{ if (0 == i || 0 == j)
    return;
  if (x[i - 1] == y[j - 1]) {
    printLCS3(i - 1, j - 1);
    printf("%c", x[i - 1]);
  }
  else if (F[i][j] == F[i - 1][j])
    printLCS3(i - 1, j);
  else
    printLCS3(i, j - 1);
}

int main(void) {
  printf("\n������� �� ���-������� ���� ���������: %u", LCS_Length());
  printf("\nPrintLCS:  ���������� ���� ��������� (� ������� ���): ");
  printLCS();
  printf("\nPrintLCS2: ���������� ���� ���������: ");
  printLCS2(strlen(x), strlen(y));
  printf("\nPrintLCS3: ���������� ���� ���������: ");
  printLCS3(strlen(x), strlen(y));
  return 0;
}