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
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
      if (m[i].key > m[j].key) {
        struct CElem tmp = m[i];
        m[i] = m[j];
        m[j] = tmp;
      }
}

unsigned getMaxPower2(unsigned k)              /* ����� ������������ ������ �� 2, ��-����� �� k */
{ unsigned pow2;
  for (pow2 = 1; pow2 <= k; pow2 <<= 1) ;
  return pow2 >> 1;
}
	
unsigned binSearch(int key)                    /* �������� ������� ������� */
{ unsigned i, l;
  i = getMaxPower2(n);
  l = m[i].key >= key ? 0 : n - i + 1;
  while (i > 1) {
    i = i >> 1;
    if (m[l+i].key < key)
      l += i;
  }
  return (l < MAX && m[++l].key == key ? l : NOT_FOUND);
}
	
void binInsert(int key, int data)               /* �������� �� ��� ������� */
{ m[++n].key = key;
  m[n].data = data;
}

void binPrint(void)                             /* ������� ������� �� ������ */
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