#include <stdio.h>
#define MAX 100

const int x[MAX] = {100, 10, 15, 5, 25, 22, 12, 22}; /* ������ */
                   /* �������� ������� �� x[] �� �� ��������! */
const unsigned n = 7; /* ���� �������� � �������� */

unsigned LNS[MAX]; /* ������� �� ������������ ������ � ������ x[i] */
unsigned next[MAX]; /* ������ �� ������� ������� */

/* ������ ��������� �� ���-������� ������������ ��������� */
unsigned LNS_Length(unsigned *start)
{ unsigned i, j;
  unsigned l;       /* � ������� �� ����������� �� xi, 
                    /* l � ��������� �� ������������ ��������� � ������ xj: */
                    /*    1) i < j <= n � */
                    /*    2) xi <= xj     */
  unsigned len = 0; /* ���������� (�� �������) ������� �� ������������ ��������� */
  for (i = n; i >= 1; i--) {
    for (l = 0, j = i + 1; j <= n; j++)
      if (x[j] >= x[i] && LNS[j] > l) {
        l = LNS[j];
        next[i] = j;
      }
    LNS[i] = l + 1;
    if (LNS[i] > len) {
      len = LNS[i];
      *start = i;
    }
  }
  return len;
}

/* ������� ���-������� ������������ ��������� */
void LNS_Print(unsigned start)
{ for (; LNS[start] >= 1; start = next[start])
    printf(" %d", x[start]);
}

int main(void) {
  unsigned start;
  printf("������� �� ���-������� ������������ ���������: %u\n", LNS_Length(&start));
  printf("�����������: "); LNS_Print(start);
  return 0;
}
