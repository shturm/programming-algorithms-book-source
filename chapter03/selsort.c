#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX           100
#define TEST_LOOP_CNT 100

struct CElem {
  int key;
  /* ............. 
    ������� ����� 
  ............. */
};

void swap(struct CElem *x1, struct CElem *x2)
{ struct CElem tmp = *x1; *x1 = *x2; *x2 = tmp; }

void init(struct CElem m[], unsigned n)             /* ������� ������ ��� �������� ���� ����� */
{ unsigned i;
  srand(time(NULL));
  for (i = 0; i < n; i++)
    m[i].key = rand() % n;
}

void straightSelection(struct CElem m[], unsigned n)
{ unsigned i, j;
  for (i = 0; i < n-1; i++)
    for (j = i+1; j <= n; j++)
      if (m[i].key > m[j].key)
        swap(m+i, m+j);
}

void print(struct CElem m[], unsigned n)            /* ������� ��������� �� ������ �� ������ */
{ unsigned i;
  for (i = 0; i < n; i++)
    printf("%8d", m[i].key);
}

void check(const struct CElem m[],
           const struct CElem saveM[],
           unsigned n)
{ unsigned i, j;
  char *found; /* ������� �� ���� ����� �� ����� ��� */

  /* 1. �������� �� ������� ��� �������� ��� */
  for (i = 0; i < n-1; i++)
    assert(m[i].key <= m[i + 1].key);

  /* 2. �������� �� ���������� �� ��������� �������� */
  found = (char *) calloc(n + 1, sizeof(*found));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if (!found[j] && m[i].key == saveM[j].key) {
        found[j] = 1;
        break;
      }

    assert(j < n);               /* �������, ��� �� � ������� ��������� */
  }

  free(found);
}

int main(void)
{ struct CElem m[MAX], saveM[MAX];
  unsigned loopInd;
  for (loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++) {
    printf("\n<<<<< ���� %u >>>>>\n", loopInd);
    init(m, MAX);
    memcpy(saveM, m, sizeof(m));  /* ������� �� ����� �� ������ */
    printf("������� ����� �����������:\n");
    print(m, MAX);
    straightSelection(m, MAX);
    printf("������� ���� �����������:\n");
    print(m, MAX);
    check(m, saveM, MAX);
  }
  return 0;
}