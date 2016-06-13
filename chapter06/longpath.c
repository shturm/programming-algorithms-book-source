#include <stdio.h>

/* ���������� ���� ������� � ����� */
#define MAXN 200

/* ���� ������� � ����� */
const unsigned n = 6;
/* ������� �� ��������� �� ����� */
const char A[MAXN][MAXN] = {
  { 0, 10, 0,  5,  0,  0 },
  { 0,  0, 5,  0,  0, 15 },
  { 0,  0, 0, 10,  5,  0 },
  { 0, 10, 0,  0, 10,  0 },
  { 0,  5, 0,  0,  0,  0 },
  { 0,  0, 0,  0,  0,  0 }};

unsigned vertex[MAXN], savePath[MAXN];
char used[MAXN];
int maxLen, tempLen, si;

void addVertex(unsigned i)
{ unsigned j, k;
  if (tempLen > maxLen) { /* �������� ��� ��-����� ��� => ��������� �� */
    maxLen = tempLen;
    for (j = 0; j < i; j++) savePath[j] = vertex[j];
    si = i;
  }
  for (k = 0; k < n; k++) {
    if (!used[k]) {       /* ��� ������ k �� ������� � ���� �� ������� */
      if (0 == i || A[vertex[i - 1]][k] > 0) {  /* ��� ������, ����� ��������, � ������� �� ��������� �� �������� */
        if (i > 0) tempLen += A[vertex[i - 1]][k];
        used[k] = 1;    /* ��������� k ���� �������� � ����; */
        vertex[i] = k;  /* �������� ����� k ��� ����; */
        addVertex(i + 1);
        used[k] = 0;    /* ������� �� ���������� */
        if (i > 0) tempLen -= A[vertex[i - 1]][k];
      }
    }
  }
}

int main(void) {
  unsigned i;
  maxLen = 0; tempLen = 0; si = 0;
  for (i = 0; i < n; i++) used[i] = 0;
  addVertex(0);
  printf("���-������� ��� �: \n");
  for (i = 0; i < si; i++) printf("%u ", savePath[i] + 1);
  printf("\n� ���� ������� %d\n", maxLen);
  return 0;
}
