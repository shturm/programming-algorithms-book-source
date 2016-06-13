#include <stdio.h>

#define MAX 10

typedef int data;
data queue[MAX];
int front, rear, empty;

void init(void) { front = rear = 0; empty = 1; }

void put(data i)
{ if (front == rear && !empty) { /* �������� �� ���������� */
    /* ���������� - ��������� �� �����, � �������� �� � ������ */
    fprintf(stderr, "����������! \n");
    return;
  }
  queue[rear++] = i;
  if (rear >= MAX) rear = 0;
  empty = 0;
}

data get(void)
{ data x;
  if (empty) { /* �������� �� ������ ������ */
    fprintf(stderr, "�������� � ������! \n");
    return 0;
  }  
  x = queue[front++];
  if (front >= MAX) front = 0;
  if (front == rear) empty = 1;
  return x;
}

int main(void) { 
  data p;
  int i;
  init();
  for (i = 0; i < 2 * MAX; i++) {
    put(i);
    p = get();
    printf("%d ", p);
  }

  printf("\n");

  /* ���� �� ������� ���������� ��� ���������� ��������� */
  for (i = 0; i < MAX + 1; i++) put(i);

  /* ���� �� ������� ������ ��� ���������� ����������, ��� ���� �������� � ������ */
  for (i = 0; i < MAX + 1; i++) get();
  return 0;
}
