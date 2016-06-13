#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define TEST_LOOP_CNT 100

#define STEPS_CNT 4
#define steps0 40
const unsigned steps[STEPS_CNT] = { steps0, 13, 4, 1 };

struct  CElem {
  int key;
  /* .............
     ������� �����
     ............. */
};

void init(struct CElem m[], unsigned n) /* ������� ������ ��� �������� ���� ����� */
{ unsigned i;
  srand(time(NULL));
  for (i = 1; i <= n; i++)
    m[i].key = rand() % n;
}

void shellSort(struct CElem m[], unsigned n)
{ int i,j,k,s;
  unsigned stepInd;
  struct CElem x;

  for (stepInd = 0; stepInd < STEPS_CNT; stepInd++) {
    s = -(k = steps[stepInd]); /* ����������� */
    for (i = k + 1; i <= (int)n; i++) {
      x = m[i]; 
      j = i - k;
      if (0 == s)
        s = -k;
      m[++s] = x;
      while (x.key < m[j].key) {
         m[j + k] = m[j];
         j -= k;
      }
      m[j + k] = x;
    }
  }
}

void print(struct CElem m[], unsigned n) /* ������� ��������� �� ������ �� ������ */
{ unsigned i;
  for (i = 1; i <= n; i++)
    printf("%8d", m[i].key);
}

void check(const struct CElem m[], const struct CElem saveM[], unsigned n)
{ unsigned i, j;
  char *found; /* ������� �� ���� ����� �� ����� ��� */

  /* 1. �������� �� ������� ��� �������� ��� */
  for (i = 1; i < n; i++)
    assert(m[i].key <= m[i+1].key);

  /* 2. �������� �� ���������� �� ��������� �������� */
  found = (char *) calloc(n+1,sizeof(*found));
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      if (!found[j] && m[i].key == saveM[j].key) {
	    found[j] = 1;
	    break;
      }
    assert(j <= n); /* �������, ��� �� � ������� ��������� */
  }
  free(found);
}

int main(void) {
  struct CElem pm[MAX + steps0 + 2], saveM[MAX + 1], *m;
  unsigned loopInd;
  m = pm + steps0 + 1;
  printf("start -- \n");
  for (loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++) {
    init(m,MAX);
    memcpy(saveM, m, (MAX+1)*sizeof(*m)); /* ������� �� ����� �� ������ */
    printf("������� ����� �����������:\n");
    print(m,MAX);
    shellSort(m,MAX);
    printf("������� ���� �����������:\n");
    print(m,MAX);
    check(m,saveM,MAX);
  }
  return 0;
}