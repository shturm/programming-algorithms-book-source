#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX           100
#define FACTOR        5
#define MAX_VALUE     (MAX*FACTOR)
#define TEST_LOOP_CNT 100

void init(unsigned m[], unsigned n) /* ������� ������ ��� �������� ���� ����� */
{ unsigned i;
  srand(time(NULL));
  for (i = 0; i < n; i++)
    m[i] = rand() % n;
}

void countSort(unsigned m[], unsigned n) /* ������� ���� ������ */
{ unsigned char cnt[MAX_VALUE];
  unsigned i,j;

  /* 0. �������������� �� ����������� */
  for (i = 0; i < MAX_VALUE; i++)
    cnt[i] = 0;

  /* 1. ��������� �� ����������� */
  for (j = 0; j < n; j++) {
    assert(m[j] >= 0 && m[j] < MAX_VALUE);
    cnt[m[j]]++;
  }

  /* 2. ���������� �� ��������� ���������������� */
  for (i = j = 0; i < MAX_VALUE; i++)
    while (cnt[i]--)
      m[j++] = i;

  assert(j == n);
}

void print(unsigned m[], unsigned n) /* ������� ��������� �� ������ �� ������ */
{ unsigned i;
  for (i = 0; i < n; i++)
    printf("%8u", m[i]);
}

void check(const unsigned m[], const unsigned saveM[], unsigned n)
{ unsigned i, j;
  char *found; /* ������� �� ���� ����� �� ����� ��� */

  /* 1. �������� �� ������� ��� �������� ��� */
  for (i = 0; i < n-1; i++)
    assert(m[i] <= m[i+1]);

  /* 2. �������� �� ���������� �� ��������� �������� */
  found = (char *) calloc(n+1,sizeof(*found));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if (!found[j] && m[i] == saveM[j]) {
	    found[j] = 1;
	    break;
      }
    assert(j < n); /* �������, ��� �� � ������� ��������� */
  }
  free(found);
}

int main(void) {
  unsigned m[MAX], saveM[MAX];
  unsigned loopInd;
  printf("start -- \n");
  for (loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++) {
    init(m,MAX);
    memcpy(saveM, m, sizeof(m)); /* ������� �� ����� �� ������ */
    printf("������� ����� �����������:\n");
    print(m,MAX);
    countSort(m,MAX);
    printf("������� ���� �����������:\n");
    print(m,MAX);
    check(m,saveM,MAX);
  }
  return 0;
}