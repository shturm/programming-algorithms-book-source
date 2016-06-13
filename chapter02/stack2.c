#include <stdio.h>
#define MAX 10

typedef int data;
data stack[MAX];
int top;

void init(void) { top = 0; }

void push(data i)
{ if (MAX == top)
    fprintf(stderr, "���������� �� �����! \n");
  else
    stack[top++] = i;
}

data pop(void)
{ if (0 == top) {
    fprintf(stderr, "������ � ������! \n");
    return 0;
  }
  else
    return stack[--top];
}

int empty(void) { return (0 == top); } 

int main(void) {
  data p;
  init();

  /* ����� �� ���� ����� �� ������������ �� ��������� �� 0 � �� �������� � ����� */
  scanf("%d", &p);
  while (0 != p) {
    push(p);
    scanf("%d", &p);
  };

  /* ��������� �� �������������� ������ �������� �� ����� � �� �������. ���� ��
   * ������ �� ����������� �� ������������ ���������� ���������������� � ������� ���
   */
  while (!empty()) printf("%d ", pop());
  printf("\n");
  return 0;
}
