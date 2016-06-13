#include <stdio.h>
#define MAXN 50
#define INFINITY (int)((1 << (sizeof(int)*8 - 1)) - 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct {
  long min, max;
  unsigned lenMin, lenMax;
} F[MAXN][MAXN];  /* ������ ������� Fmin() � Fmax() */

const unsigned n = 7;      /* ���� ����� */
const long x[MAXN] = { 0, 9, -3, 8, 7, -8, 0, 7 }; /* ��������� �� ������� (��� �������) */
char sign[MAXN] = { ' ', '+', '*', '*', '-', '+', '*', '-' }; /* ����� ����� ��� */

/* �������� ���������� */
long oper(long v1, char sign, long v2)
{ switch (sign) {
    case '+': return v1 + v2;
    case '-': return v1 - v2;
    case '*': return v1 * v2;
  }
  return 0;
}

/* �������� ����������� �� �������� ������� */
void calculate(unsigned beg, unsigned len)
{ unsigned i, beg2;
  long val1, val2, val3, val4, minValue, maxValue;
  if (beg > n)
	beg -= n;
  if (F[beg][len].min != INFINITY) /* ���������� ���� � ���� �������� */
	return;
  if (1 == len) {
    F[beg][len].min = F[beg][len].max = x[beg];
    F[beg][len].lenMin = F[beg][len].lenMax = 0;
    return;
  }
  /* ���������� ������ �� �� ��������� */
  F[beg][len].min = INFINITY;
  F[beg][len].max = -INFINITY;
  for (i = 1; i < len; i++) {
    /* ���������� �� ������ ��������� F[beg][i] � F[beg+i][len-i] */
    calculate(beg, i);
    if (beg + i > n)
	   beg2 = beg + i - n;
	else
	   beg2 = beg + i;
    calculate(beg2, len - i);
    val1 = oper(F[beg][i].min, sign[beg2 - 1], F[beg2][len - i].min);
    val2 = oper(F[beg][i].min, sign[beg2 - 1], F[beg2][len - i].max);
    val3 = oper(F[beg][i].max, sign[beg2 - 1], F[beg2][len - i].min);
    val4 = oper(F[beg][i].max, sign[beg2 - 1], F[beg2][len - i].max);
    /* ������������� �� ����������� �������� �� F[beg][len] */
    minValue = MIN(val1, MIN(val2, MIN(val3, val4)));
    if (minValue < F[beg][len].min) {
      F[beg][len].min = minValue;
      F[beg][len].lenMin = i;
    }
    /* ������������� �� ������������ �������� �� F[beg][len] */
    maxValue = MAX(val1, MAX(val2, MAX(val3, val4)));
    if (maxValue > F[beg][len].max) {
      F[beg][len].max = maxValue;
      F[beg][len].lenMax = i;
    }
  }
}

/* ������� �����, �� ����� �� �������� min/max */
void printMinMax(unsigned beg, unsigned len, char printMin)
{ unsigned i, beg2;
  if (beg > n)
	 beg -= n;
  if (1 == len)
    printf("%ld", x[beg]);
  else {
    if (len < n)
	  printf("(");
    i = printMin ? F[beg][len].lenMin : F[beg][len].lenMax;
	if ((beg2 = beg + i) > n)
	  beg2 -= n;
    printMinMax(beg, i, printMin); /* �������� �� ������ ���� �� ������ */
    printf("%c", sign[beg2 - 1]); /* ��������� �� ���������� */
    printMinMax(beg2, len - i, printMin); /* �������� �� ������� ���� �� ������ */
    if (len < n)
	  printf(")");
  }
}

/* ������ ��������� � ��������, ����� � ��� �� ��������� */
void solve(void)
{ unsigned i, j;
  /* ������������� */
  sign[0] = sign[n];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
	  F[i][j].min = INFINITY;
  /* ���������� �� ����������� �� �������� ������� */
  for (i = 1; i <= n; i++)
	 calculate(i, n);
}

/* ����� � ������� ��������� � �������� */
void print(void)
{ unsigned i, minIndex, maxIndex;
  for (minIndex = 1, i = 2; i <= n; i++)
    if (F[i][n].min < F[minIndex][n].min)
	   minIndex = i;
  for (maxIndex = 1, i = 2; i <= n; i++)
    if (F[i][n].max > F[maxIndex][n].max)
	   maxIndex = i;
  printf("\n��������� ��������: %d\n", F[minIndex][n].min);
  printMinMax(minIndex, n, 1);
  printf("\n\n���������� ��������: %d\n", F[maxIndex][n].max);
  printMinMax(maxIndex, n, 0);
}

int main(void) {
  solve();
  print();
  return 0;
}