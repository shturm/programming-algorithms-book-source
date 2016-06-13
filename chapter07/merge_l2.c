#include <stdio.h>
#include <stdlib.h>
#define INFINITY (int)((1 << (sizeof(int)*8 - 1)) - 1)


struct list { /* ��� ������� ������ */
  int value;
  struct list *next;
} *z; /* ������ ������� */

const unsigned long n = 100;

/* �������� �������� ��������� */
struct list *generate(unsigned long n)
{ struct list *p, *q;
  unsigned long i;
  for (p = z, i = 0; i < n; i++) {
    q = (struct list *) malloc(sizeof(struct list));
    q->value = rand() % (2*n + 1);
    q->next = p;
    p = q;
  }
  return p;
}

void printList(struct list *p) /* ������� ������� �� ������ */
{ for (; p != z; p = p->next)
    printf("%4d", p->value);
}

struct list *merge(struct list *a, struct list *b)
{ struct list *c;
  c = z;

  /* ���������� ��, �� � ����� ������� �������� ���� �� ���� ������� */
  do {
    if (a->value < b->value) {
      c->next = a;
	  c = a;
	  a = a->next;
    }
    else {
      c->next = b;
	  c = b;
	  b = b->next;
    }
  } while (c != z);
  c = z->next;
  z->next = z;
  return c;
}

struct list *mergeSort(struct list *c)
{ struct list *a, *b;

  /* ��� �������� ������� ���� ���� �������: �� �� ����� ���� */
  if (c->next == z)
	return c;

  /* �������� �� ������� �� ��� ����� */
  for (a = c, b = c->next->next->next; b != z; c = c->next)
	b = b->next->next;
  b = c->next;
  c->next = z;

  /* ��������� ��������� �� ����� �����, ���������� �� ������� */
  return merge(mergeSort(a), mergeSort(b));
}

int main(void) {
  struct list *l;

  /* ������������� �� z */
  z = (struct list *) malloc(sizeof(struct list));
  z->value = INFINITY;
  z->next = z;

  l = generate(n);
  printf("����� �����������:\n");
  printList(l);
  l = mergeSort(l); /* ���������� ��, �� �������� ������� ���� 1 ������� */
  printf("���� �����������:\n");
  printList(l);
  return 0;
}