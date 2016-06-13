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

void interpolInit(void) { n = 0; }               /* ������������� */

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
	
unsigned interpolSearch(int key)                 /* �������� ��������������� ������� */
{ unsigned l, r, mid;
  float k;
  l = 0; r = n - 1;
  while (l <= r) {
    if (m[r].key == m[l].key)
      if (m[l].key == key)
        return l;
      else
        return NOT_FOUND;
    k = (float) (key - m[l].key) / (m[r].key - m[l].key);
    if (k < 0 || k > 1)
      return NOT_FOUND;
    mid = (unsigned)(l + k*(r-l) + 0.5);
    if (key < m[mid].key)
      r = mid - 1;
    else if (key > m[mid].key)
      l = mid + 1;
    else
      return mid;
  }
  return NOT_FOUND;
}
	
void interpolInsert(int key, int data)          /* �������� �� ��� ������� */
{ m[n].key = key;
  m[n++].data = data;
}

void interpolPrint(void)                        /* ������� ������� �� ������ */
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
    if (NOT_FOUND == (ind = interpolSearch(elem2Search)))
      printf("%s","������� � ����� ���� �� ����������!\n");
    else
      printf("%��������� � �������! �������� �� ���. ����: %d\n", m[ind].data);
  }
}

int main(void) {
  unsigned ind;
  interpolInit();
  for (ind = 0; ind < MAX; ind++)
    interpolInsert(rand() % (MAX*2), ind);
  sort();
  printf("�������� ������� �������� ��������: \n"); interpolPrint();
  printf("\n��������:\n");
  performSearchTest();
  return 0;
}