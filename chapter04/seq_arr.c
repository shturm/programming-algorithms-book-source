#include <stdio.h>
#include <stdlib.h>

#define MAX 100

#define DataType int
struct CElem {
  int key;
  DataType data;
  /* ... */
} m[MAX + 1]; /* ����� �� ������ */
unsigned n;   /* ���� �������� � ������ */

void seqInit(void) { n = 0; }              /* ������������� */

unsigned seqSearch(int key)            /* �������������� ������� */
{ unsigned x;
  m[0].key = key; /* ����������� */
  for (x = n + 1; key != m[--x].key; ) ;
  return x;
}

void seqInsert(int key, DataType data) /* ������ ��� ������� */
{ m[++n].key = key;
  m[n].data = data;
}

void seqPrint(void)                    /* ������� ������� �� ������ */
{ unsigned i;
  char buf[9];
  for (i = 1; i <= n; i++) {
    sprintf(buf, "%d|%d", m[i].key, m[i].data);
    printf("%8s", buf);
  }
}

void performSearchTest(void)
{ unsigned ind, elem2Search;

  for (elem2Search = 0; elem2Search < 2*MAX; elem2Search++) {
    printf("������ ������� � ���� %u.\n", elem2Search);
    if (0 == (ind = seqSearch(elem2Search)))
      printf("%s","������� � ����� ���� �� ����������!\n");
    else
      printf("%��������� � �������! �������� �� ���. ����: %d\n", m[ind].data);
  }
}

int main(void) {
  unsigned ind;
  seqInit();
  for (ind = 0; ind < MAX; ind++)
    seqInsert(rand() % (MAX*2), ind);
  printf("�������� ������� �������� ��������: \n"); seqPrint();
  printf("\n��������:\n");
  performSearchTest();
  return 0;
}
