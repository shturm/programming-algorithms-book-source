#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#define DataType int
struct CElem {
  int key;
  DataType data;
  struct CElem *next;
  /* ... */
} *head;

void listInit(void) { head = NULL; } /* ������������� */

void listInsert(int key, DataType data) /* ������ ��� ������� */
{ struct CElem *q = (struct CElem *) malloc(sizeof *head);
  q->key = key; q->data = data;
  q->next = head; head = q;
}

struct CElem *listSearch(int key) /* �������������� ������� � ������������� */
{ struct CElem *q, *p = head;
  if (NULL == head)
    return NULL;
  if (head->key == key) return head;
  for (q = head->next; q != NULL; )
    if (q->key != key) { 
      p = q;
      q = q->next; 
    }
    else {
      p->next = q->next;
      q->next = head;
      return (head = q);
    }
  return NULL;
}

void listPrint(void) /* ������� ������� �� ������ */
{ struct CElem *q;
  char buf[9];
  for (q = head; q != NULL; q = q->next) {
    sprintf(buf, "%d|%d", q->key, q->data);
    printf("%8s", buf);
  }
}

void performSearchTest(void)
{ unsigned elem2Search;
  struct CElem *p;

  for (elem2Search = 0; elem2Search < 2*MAX; elem2Search++) {
    printf("������ ������� � ���� %u.\n", elem2Search);
    if (NULL == (p = listSearch(elem2Search)))
      printf("%s","������� � ����� ���� �� ����������!\n");
    else
      printf("%��������� � �������! �������� �� ���. ����: %d\n", p->data);
  }
}

int main(void) {
  unsigned ind;
  listInit();
  for (ind = 0; ind < MAX; ind++)
    listInsert(rand() % (MAX*2), ind);
  printf("�������� ������� �������� ��������: \n"); listPrint();
  printf("\n��������:\n");
  performSearchTest();
  printf("�������� ���� ���������: \n"); listPrint();
  return 0;
}