#include <stdio.h>
#include <string.h>
#define MAX 100

struct ST {
  unsigned len;  /* ������� �� ������������ ������������ ���������, ���������� � i */
  unsigned back; /* ������ �� ��������� ������� � ����. ������ */
  unsigned long sum; /* ���� �� ���������� �� ������������ ������ */
} max1[MAX], max2[MAX];
unsigned x2[MAX], rez[MAX];
unsigned top, bestLen, bestSum;

const unsigned n = 9;  /* ���� ��������� ������� */
const unsigned x[MAX] = {0,10,20,15,40,5,4,300,2,1}; /* �������� �� ��������� */

/* ����� ���������� ������ */
void findIncSequence(struct ST max[], const unsigned x[])
{ unsigned i, j;
  /* ������� ����� */
  for (i = 1; i <= n; i++)
    for (j = max[i].len = max[i].sum = 0; j < i; j++)
      if (x[j] <= x[i])
        if ((max[j].len + 1 > max[i].len)
           || ((max[j].len + 1 == max[i].len) && (max[j].sum + x[i] > max[i].sum)) ) {
          max[i].back = j;
          max[i].len = max[j].len + 1;
          max[i].sum = max[j].sum + x[i];
        }
}

/* ��������� �������� ����� �� �������� */
void reverse(unsigned x2[], const unsigned x[])
{ unsigned i;
  for (i = 1; i <= n; i++)
	x2[i] = x[n-i+1];
}

/* ������ ��������� ������ */
void solve(void) {
  unsigned i;
  /* ������ (1) */
  findIncSequence(max1, x);
  /* ������ (2) */
  reverse(x2,x);
  findIncSequence(max2, x2);
  /* ������ (3) */
  for (bestLen = bestSum = 0, i = 1; i <= n; i++) {
    if (((max1[i].len + max2[n-i+1].len > bestLen))
        || ((max1[i].len + max2[n-i+1].len == bestLen)
            && (max1[i].sum + max2[n-i+1].sum > bestSum))) {
      bestLen = max1[i].len + max2[n-i+1].len;
      bestSum = max1[i].sum + max2[n-i+1].sum; /* Must be decreased by 1 */
      top = i;
    }
  }
}

/* ��������� ��������� ������ */
void buildSequence(void)
{ unsigned t, len, l;
  /* ����������� �� ������������ ���� �� �������� */
  for (l = max1[t = top].len, len = 0; t != 0; t = max1[t].back)
    rez[l-len++] = x[t];
  /* ����������� �� ������������ ���� �� �������� */
  for (t = max2[n-top+1].back; t != 0; t = max2[t].back)
    rez[++len] = x2[t];
}

/* ������� ��������� �� ������ */
void print(void)
{ unsigned i;
  printf("\n���������� ���� �������, ����� ����� �� �� �������: %u\n", bestLen-1);
  for (i = 1; i < bestLen; i++)
	printf("%u ", rez[i]);
  printf("\n");
}

int main(void) {
  solve();
  buildSequence();
  print();
  return 0;
}