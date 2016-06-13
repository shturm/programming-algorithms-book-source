#include <stdio.h>
#include <stdlib.h>

struct list { /* ��� ������� ������ */
  int value;
  struct list *next;
} *empty; /* ������ ������� */

const unsigned long n = 100;

struct list *generate(unsigned long n) { /* �������� �������� ��������� */
  struct list *p, *q;
  unsigned long i;
  for (p = NULL, i = 0; i < n; i++) {
    q = (struct list *) malloc(sizeof(struct list));
    q->value = rand() % (2*n + 1);
	q->next = p;
	p = q;
  }
  return p;
}

struct list *merge(struct list *a, struct list *b)
{ struct list *head, *tail;

  /* ���������� ��, �� � ����� ������� �������� ���� �� ���� ������� */
  tail = head = empty;
  for (;;) {
    if (a->value < b->value) {
      tail->next = a;
      a = a->next;
      tail = tail->next;
      if (NULL == a) {
        tail->next = b;
        break;
      }
    }
    else {
      tail->next = b;
      b = b->next;
      tail = tail->next;
      if (NULL == b) {
        tail->next = a;
        break;
      }
    }
  }
  return head->next;
}

struct list *mergeSort(struct list *c, unsigned long n)
{ struct list *a, *b;
  unsigned long i, n2;

  /* ��� �������� ������� ���� ���� �������: �� �� ����� ���� */
  if (n < 2)
	return c;

  /* ��������� �� ������� �� ��� ����� */
  for (a = c, n2 = n / 2, i = 2; i <= n2; i++)
	c = c->next;
  b = c->next;
  c->next = NULL;

  /* ��������� ��������� �� ����� �����, ���������� �� ������� */
  return merge(mergeSort(a, n2), mergeSort(b, n - n2));
}

void printList(struct list *p) { /* ������� ������� �� ������ */
  for (; p != NULL; p = p->next)
    printf("%4d", p->value);
}

int main(void) {
  struct list *l;
  empty = (struct list *) malloc(sizeof(struct list)); 
  l = generate(n);
  printf("����� �����������:\n"); printList(l);
  l = mergeSort(l,n);
  printf("���� �����������:\n"); printList(l);
  return 0;
}