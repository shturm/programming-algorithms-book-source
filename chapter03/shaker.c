#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX           100
#define TEST_LOOP_CNT 100

struct  CElem {
  int key;
  /* .............
     ������� �����
     ............. */
};

void swap(struct CElem *x1, struct CElem *x2)
{ struct CElem tmp = *x1; *x1 = *x2; *x2 = tmp; }

void init(struct CElem m[], unsigned n) /* ������� ������ ��� �������� ���� ����� */
{ unsigned i;
  srand(time(NULL));
  for (i = 0; i < n; i++)
    m[i].key = rand() % n;
}

void shakerSort(struct CElem m[], unsigned n)
{ unsigned k = n, r = n-1;
  unsigned l = 1, j;
  do {
    for (j = r; j >= l; j--)
      if (m[j-1].key > m[j].key) {
        swap(m+j-1,m+j);
        k = j;
      }

    l = k + 1;
    for (j = l; j <= r; j++)
      if (m[j-1].key > m[j].key) {
        swap(m+j-1,m+j);
        k = j;
      }

    r = k - 1;
  } while (l <= r);
}

void print(struct CElem m[], unsigned n) /* ������� ��������� �� ������ �� ������ */
{ unsigned i;
  for (i = 0; i < n; i++)
    printf("%8d", m[i].key);
}

void check(const struct CElem m[], const struct CElem saveM[], unsigned n)
{ unsigned i, j;
  char *found; /* ������� �� ���� ����� �� ����� ��� */

  /* 1. �������� �� ������� ��� �������� ��� */
  for (i = 0; i < n-1; i++)
    assert(m[i].key <= m[i+1].key);

  /* 2. �������� �� ���������� �� ��������� �������� */
  found = (char *) calloc(n+1,sizeof(*found));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if (!found[j] && m[i].key == saveM[j].key) {
	    found[j] = 1;
	    break;
      }
    assert(j < n); /* �������, ��� �� � ������� ��������� */
  }
  free(found);
}

int main(void) {
  struct CElem m[MAX], saveM[MAX];
  unsigned loopInd;
  printf("start -- \n");
  for (loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++) {
    init(m,MAX);
    memcpy(saveM, m, sizeof(m)); /* ������� �� ����� �� ������ */
    printf("������� ����� �����������:\n");
    print(m,MAX);
    shakerSort(m,MAX);
    printf("������� ���� �����������:\n");
    print(m,MAX);
    check(m,saveM,MAX);
  }
  return 0;
}