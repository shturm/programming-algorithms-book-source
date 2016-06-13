#include <stdio.h>
#define CDataType char

unsigned count(CDataType m[], unsigned size, CDataType candidate)
{ unsigned cnt, i;
  for (i = cnt = 0; i < size; i++)
    if (m[i] == candidate)
      cnt++;
  return cnt;
}

char findMajority(CDataType m[], unsigned size, CDataType *majority)
{ unsigned i, size2 = size / 2;
  for (i = 0; i < size; i++)
    if (count(m, size, m[i]) > size2) {
      *majority = m[i];
      return 1;
    }

  return 0;
}

int main(void) {
  CDataType majority;
  if (findMajority("AAACCBBCCCBCC", 13, &majority))
    printf("��������: %c\n", majority);
  else
    printf("���� ��������.\n");
  return 0;
}