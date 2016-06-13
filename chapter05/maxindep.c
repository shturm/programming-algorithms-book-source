#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 200

/* ���� ������� � ����� */
const unsigned n = 8;
/* ������� �� ��������� �� ����� */
const char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 0, 1, 1, 0, 1, 0, 0 },
  { 1, 1, 0, 0, 1, 0, 1, 1 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 1, 0, 0, 0, 0, 1, 0, 0 }
};

unsigned S[MAXN], T[MAXN], sN, tN;

void print(void)
{ unsigned i;
  printf("{ ");
  for (i = 0; i < n; i++)
    if (T[i]) printf("%u ", i + 1);
  printf("} \n");
}

void maxSubSet(unsigned last)
{ unsigned i, j;
  if (sN + tN == n) {
    print(); /* SuT=V -> ��������� �� ��������� */
    return;
  }
  for (i = last; i < n; i++) {
    if (!S[i] && !T[i]) {
      for (j = 0; j < n; j++)
        if (A[i][j] && !S[j]) {
          S[j] = last+1; sN++;
        }
      T[i] = 1; tN++;
      maxSubSet(i+1);     /* �������� */
      T[i] = 0; tN--;
      for (j = 0; j < n; j++)
        if (S[j] == last+1) { S[j] = 0; sN--; }
    }
  }
}

void main(void) {
  unsigned i;
  printf("��� ������ ���������� ���������� ��������� � �����:\n");
  sN = tN = 0;
  for (i = 0; i < n; i++) S[i] = T[i] = 0;
  maxSubSet(0);
}
