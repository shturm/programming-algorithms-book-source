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

  /* ������������, �� � ����� ������� �������� ���� �� ���� ������� */
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
{ unsigned long i, n, n2;
  struct list *a, *b, *head, *todo, *t;
  head = (struct list *) malloc(sizeof(struct list));
  head->next = c;
  a = z;
  for (n = 1; a != head->next; n <<= 1) {
    todo = head->next;
    c = head;
    while (todo != z) {
      t = todo;
      /* �������� �� a[] */
      for (a = t, i = 1; i < n; i++)
		t = t->next;
      /* �������� �� b[] */
      b = t->next; t->next = z;
      for (t = b, i = 1; i < n; i++)
		t = t->next;
      /* ������� �� a[] � b[] */
      todo = t->next; t->next = z;
      c->next = merge(a, b);
      /* ���������� �� ������ ����� */
      for (n2 = n + n, i = 1; i <= n2; i++)
		c = c->next;
    }
  }
  return head->next;
}

int main(void) {
  struct list *h;

  /* ������������� �� z */
  z = (struct list *) malloc(sizeof(struct list));
  z->value = INFINITY;
  z->next = z;

  h = generate(n);
  printf("����� �����������:\n");
  printList(h);
  h = mergeSort(h); /* ������������, �� �������� ������� ���� 1 ������� */
  printf("���� �����������:\n");
  printList(h);
  return 0;
}