#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX    12
#define ARRAYS 6

struct CElem {
  int key;
  /* .............
     ������� �����
     ............. */
};

struct CList {
  unsigned len, point;
  struct CElem data[MAX];
  struct CList *next;
};

struct CList *init(unsigned mod)  /* ������� ������ ��� �������� ���� ����� */
{ struct CList *head, *p;
  unsigned i, j;
  srand(time(NULL));
  for (head = NULL, i = 0; i < ARRAYS; i++) {
    p = (struct CList *) malloc(sizeof(struct CList));
    p->len = MAX;
    p->point = 0;
    p->data[0].key = (rand() % mod);
    for (j = 1; j<MAX; j++)
      /* �������� ��������� ���������������� */
      p->data[j].key = p->data[j-1].key + (rand() % mod);
    p->next = head;
    head = p;
  }

  return head;
}

void merge(struct CList *head) {
  struct CList *p, *q, *pMin;
  struct CElem k1, k2;
  int i;
  printf("\n");
  p = (struct CList *) malloc(sizeof(struct CList));
  p->next = head;
  head = p;
  for (i = 0; i < MAX*ARRAYS; i++) {
    p = head; pMin = head;
    while (NULL != p->next) {
      k1 = p->next->data[p->next->point];
      k2 = pMin->next->data[pMin->next->point];
      if (k1.key < k2.key)
        pMin = p;
      p = p->next;
    }
    printf("%8d", pMin->next->data[pMin->next->point].key);
    if (pMin->next->len-1 == pMin->next->point) {
      q = pMin->next;
      pMin->next = pMin->next->next;
      free(q);
    }
    else
      pMin->next->point++;
  }
}

void print(struct CList *head)
{ unsigned i;
  for (; NULL != head; head = head->next) {
    for (i = 0; i < MAX; i++)
      printf("%6d", head->data[i].key);
    printf("\n");
  }
  printf("\n");
}

int main(void)
{ struct CList *head;
  head = init(500);
  printf("\n�������� ����� �����������:\n");
  print(head);
  printf("���������� �� ���������:");
  merge(head);
  return 0;
}