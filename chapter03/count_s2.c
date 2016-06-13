#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define FACTOR 5
#define MAX_VALUE (MAX*FACTOR)
#define TEST_LOOP_CNT 100

struct CElem {
  int key;
  /* .............
     ������� �����
     ............. */
};

struct CList {
  struct CElem data;
  struct CList *next;
};

void init(struct CElem m[], unsigned n) /* ������� ������ ��� �������� ���� ����� */
{ unsigned i;
  srand(time(NULL));
  for (i = 0; i < n; i++)
    m[i].key = rand() % MAX_VALUE;
}

void countSort(struct CElem m[], unsigned n)
{ /* ������� ����� �� ������ �� ��������. �������� - ���������� �����! */
  unsigned i,j;
  struct CList *lst[MAX_VALUE], *p;

  /* 0. ������� ������������� */
  for (i = 0; i < MAX_VALUE; i++)
    lst[i] = NULL;

  /* 1. ������������ �� ���������� �� ������� */
  for (j = 0; j < n; j++) {
    /* 1.1. �������� �� ����� */
    assert(m[j].key >= 0 && m[j].key < MAX_VALUE);
    /* 1.2. �������� �� �������� � �������� �� ������� */
    p = (struct CList *) malloc(sizeof(struct CList));
    p->data = m[j];
    p->next = lst[m[j].key];
    lst[m[j].key] = p;
  }

  /* 2. ��������� �� ��������� �� ����������� ���������������� */
  for (i = j = 0; i < MAX_VALUE; i++)
     while (NULL != (p = lst[i])) {
	   m[j++] = lst[i]->data;
	   lst[i] = lst[i]->next;
	   free(p);
     }
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
  found = (char *) calloc(n,sizeof(*found));
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
  for (loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++) {
    printf("\n<<<<< ���� %u >>>>>\n", loopInd);
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