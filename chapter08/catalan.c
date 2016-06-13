#include <stdio.h>
#include <math.h>
#define MAX 80
#define INFINITY 1e20

double d[MAX][MAX];   /* ���������� ����� ��������� */
double m[MAX][MAX];   /* ������� - ������ ������� */

const struct {        /* ���������� �� ��������� */
  int x;
  int y;
} coord[MAX] = {{1,1},{5,-2},{10,1},{7,7},{1,7}};
const unsigned n = 5; /* ���� ������� */

/* �������� ������������ ����� ������ ������ ������� */
void calcDist(void)
{ unsigned i, j;
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      d[i][j] = sqrt((coord[i].x - coord[j].x) * (coord[i].x - coord[j].x) +
                     (coord[i].y - coord[j].y) * (coord[i].y - coord[j].y));
}

/* ������� �������, ��������� ���������� ���� ���������, ���������� ��
 * ����������� �� ����� ������ �������, ����� � ��������, �� ����� �� ������� */
void solve(void)
{ unsigned i, j, k;
  for (i = 1; i < n; i++)
	 m[i][i] = 0; /* ������������� */
  for (j = 1; j < n; j++) {            /* ������� ����� */
    for (i = 1; i < n - j; i++) {
      m[i][i + j] = INFINITY;
      for (k = i; k < i + j; k++) {
        double t = m[i][k] +
          m[k+1][i+j] +
          d[i-1][k] +
          d[k][i+j] +
          d[i-1][i+j];
        if (t < m[i][i+j]) {          /* ����������� �� �������� ������� */
          m[i][i+j] = t;
          m[i+j][i] = k;
        }
      }
    }
  }
}

/* ����������� �� ��������� */
void printResult(void)
{ unsigned i;
  double p = d[0][n-1];  /* ���������� ���������� */
  for (i = 0; i < n; i++)
	 p += d[i][i+1];
  printf("\n��������� �� ���������� ������ � %.2lf", (m[1][n-1] - p) / 2);
}

/* ��������� �� ���������� ������ �� ������ */
void writeCut(unsigned ll, unsigned rr)
{ if (ll != rr) {
    writeCut(ll, (unsigned) m[rr][ll]);
    writeCut((unsigned) m[rr][ll] + 1, rr);
    if (ll != 1 || rr != n-1)
	  printf("(%u,%u) ", ll, rr + 1);
  }
}

int main(void) {
  calcDist();
  solve();
  printResult();
  printf("\n��������� �� ���������� ������: ");
  writeCut(1, n-1);
  return 0;
}