#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define NOT_FOUND (unsigned)(-1)

#define DataType int
struct CElem { 
  int key;
  DataType data;
  /* ... */
} m[MAX];   /* ����� �� ������ */
unsigned n; /* ���� �������� � ������ */

void binInit(void) { n = 0; }                    /* ������������� */

void sort(void)                                  /* ��������� */
{ unsigned i,j;
  for (i = 0; i < n-1; i++)
    for (j = i + 1; j < n; j++)
      if (m[i].key > m[j].key) {
        struct CElem tmp = m[i];
        m[i] = m[j];
        m[j] = tmp;
      }
}
	
unsigned binSearch(int key)                     /* �������� ������� ������� */
{ int l = 0, r = n-1, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (key < m[mid].key)
      r = mid - 1;
    else if (key > m[mid].key)
      l = mid + 1;
    else
      return mid;
  }
  return NOT_FOUND; 
}
	
void binInsert(int key, int data)               /* �������� �� ��� ������� */
{ m[n].key = key;
  m[n++].data = data;
}

void binPrint(void)                             /* ������� ������� �� ������ */
{ unsigned i;
  char buf[9];
  for (i = 0; i < n; i++) {
    sprintf(buf, "%d|%d", m[i].key, m[i].data);
    printf("%8s", buf);
  }
}

void performSearchTest(void)
{ unsigned ind, elem2Search;
  for (elem2Search = 0; elem2Search < 2*MAX; elem2Search++) {
    printf("������ ������� � ���� %u.\n", elem2Search);
    if (NOT_FOUND == (ind = binSearch(elem2Search)))
      printf("%s","������� � ����� ���� �� ����������!\n");
    else
      printf("%��������� � �������! �������� �� ���. ����: %d\n", m[ind].data);
  }
}

int main(void) {
  unsigned ind;
  binInit();
  for (ind = 0; ind < MAX; ind++)
    binInsert(rand() % (MAX*2), ind);
  sort();
  printf("�������� ������� �������� ��������: \n"); binPrint();
  printf("\n��������:\n");
  performSearchTest();
  return 0;
}