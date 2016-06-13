#include <stdio.h>
#include <string.h>
#define MAX     30          /* ���������� ���� ������� �� ����� */
#define LETTERS 26          /* ���� ����� */

const struct { /* ���������, ������� � ���������: S->a */
  char S, a;
} prodT[MAX+1] = {
	{0,0},     /* �� �� �������� */
	{'S','s'}, /* S->s */
	{'A','a'}, /* A->a */
	{'B','b'}  /* B->b */
};             
const unsigned cntT = 3;                /* ���� ������� �� ���� 1: S->a */
const char string[MAX + 1] = "aaasbbb"; /* ���, ����� ����������� �� ������������� ��� ����������� */

const struct { /* ���������, ������� � �����������: S->AB */
  char S, A, B;
} prodNT[MAX+1] = {
	{0,0,0},       /* �� �� �������� */
	{'S','A','R'}, /* S->AR */
	{'S','A','B'}, /* S->AB */
	{'R','S','B'}, /* R->SB */
};
const unsigned cntNT = 3;               /* ���� ������� �� ���� 2: S->AB */

unsigned char t[LETTERS][MAX][MAX]; /* ������ ������� */

/* ��������� */
unsigned cfl(void)
{ unsigned i, j, k, l, d, let, n;
  /* ������������� */
  n = strlen(string); /* ������� �� ������������ ��� */
  /* ��������� ������ � "��������" */
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      for (let = 0; let < LETTERS; let++)
		t[let][i][j] = 0;
  /* ������������ � ������ ������ �������� ���������, ����� �� ������ ������ */
  for (i = 1; i <= cntT; i++)
    for (j = 1; j <= n; j++)
      if (prodT[i].a == string[j - 1])
		 t[prodT[i].S - 'A'][j][j] = 1;
  /* ������� ����� �� ��������� �� ��� 2 */
  for (d = 1; d < n; d++)
    for (i = 1; i <= n - d; i++)
      for (j = i + d, k = 1; k <= cntNT; k++) /* �� ����� ���������� S �� ���� ���� �� ������� */
        for (l = i; l <= j - 1; l++)
          if (t[prodNT[k].A - 'A'][i][l] && t[prodNT[k].B - 'A'][l + 1][j])
            t[prodNT[k].S - 'A'][i][j] = 1;
  return t['S' - 'A'][1][n];
}

int main(void) {
  printf("\n����� %s%s", cfl() ? "" : "�� ", "�� ������� �� �����������!");
  return 0;
}