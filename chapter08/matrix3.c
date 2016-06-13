#include <stdio.h>
#define MAX 100
#define INFINITY (unsigned long)(-1)

unsigned long m[MAX][MAX];    /* ������� - ������ ������� */
struct {
  unsigned left, right;
} order[MAX * MAX];           /* ��� �� ��������� �� ��������� */
unsigned long cnt;            /* ���� �������� �� ������������ */

const unsigned long r[MAX+1] = {12,13,35,3,34,2,21,10,21,6}; /* ����������� �� ��������� */
const unsigned n = 9;         /* ���� ������� */

/* ������� �������, ��������� ���������� ���� ���������, ���������� ��
 * ����������� �� ����� ������ �������, ����� � ��������, �� ����� �� ������� */
void solve(void)
{ unsigned i, j, k;
  /* ������������� */
  for (i = 1; i <= n; i++)
	m[i][i] = 0; 
  /* ������� ����� */
  for (j = 1; j <= n; j++) {            
    for (i = 1; i <= n - j; i++) {
      m[i][i + j] = INFINITY;
      for (k = i; k < i + j; k++) {
        unsigned long t = m[i][k] + m[k + 1][i + j] + r[i-1] * r[k] * r[i + j];
		/* ����������� �� �������� ������� */
        if (t < m[i][i + j]) {          
          m[i][i + j] = t;
          m[i + j][i] = k;
        }
      }
    }
  }
}

unsigned buildOrder(unsigned ll, unsigned rr) /* ������� ��������� �� ��������� */
{ long ret = cnt++;
  if (ll < rr) {
    order[ret].left = buildOrder(ll, m[rr][ll]);
    order[ret].right = buildOrder(m[rr][ll] + 1, rr);
  }
  else {
    order[ret].left = ll;
    order[ret].right = rr;
  }
  return ret;
}

void printMatrix(void) /* ������� ��������� �� ���������� �� ������ */
{ unsigned i, j;
  printf("\n������� �� ���������� :");
  for (i = 1; i <= n; i++) {
    printf("\n");
    for (j = 1; j <= n; j++)
	   printf("%8lu", m[i][j]);
  }
}

void printMultiplyPlan(void) /* ������� ���� �� ��������� �� ��������� */
{ unsigned long i;
  printf("\n���� �� ��������� �� ���������:");
  for (i = 0; i < cnt; i++) {
    if (order[i].left == order[i].right)
      printf("\nL[%lu] = M%u", i, order[i].left);
    else
      printf("\nL[%lu] = L[%u] * L[%u]", i, order[i].left, order[i].right);
  }
}

void getOrder(unsigned ll, unsigned rr) /* �������� ���� �� ��������� � ������� �� ����� */
{ if (ll == rr)
    printf("M%u", ll);
  else {
    printf("(");
    getOrder(ll, m[rr][ll]);
    printf("*");
    getOrder(m[rr][ll] + 1, rr);
    printf(")");
  }
}

int main(void) {
  solve();
  cnt = 0;
  buildOrder(1, n);
  printf("\n����������� ���� ��������� �: %lu", m[1][n]);
  printMatrix();
  printMultiplyPlan();
  printf("\n��� �� ��������� �� ���������: ");
  getOrder(1, n);
  return 0;
}