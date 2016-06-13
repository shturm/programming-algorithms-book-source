#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
const char *message = "LLLLLLALABALANICAAAABABABBABABABABAAABABALLLLAABB";

void LPCencode(int *code, const char *msg) /* �������� LPC �������� �� ����������� */
{ double exp;
  unsigned n;
  if ('\0' == *msg) return; /* ������ ������ ��������� */
  for (exp = code[0] = *msg++, n = 1; '\0' != *msg; n++, msg++) {
    code[n] = (int) ceil(exp-*msg);
    exp = (exp*n + (unsigned char)*msg)/(n+1);
  }
}

void LPCdecode(char *msg, const int *code, const unsigned n) /*�������� LPC ����������*/
{ double exp;
  unsigned i;
  for (exp = *msg++ = *code, i = 1; i < n; i++, msg++) {
    *msg = (char)ceil(exp - code[i]);
    exp = (exp*i + (unsigned char) *msg) / (i+1);
  }
  *msg = '\0';
}

void print(const int *code, const unsigned n)
{ unsigned i;
  for (i = 0; i < n; i++)
    printf("%4d", code[i]);
}

int main(void) {
  int coded[MAX];    /* �������� ��������� */
  char decoded[MAX]; /* ���������� ��������� */

  printf("������ ���������:\n%s\n", message);

  LPCencode(coded, message);
  printf("\n�������� ���������:\n");
  print(coded, strlen(message));

  LPCdecode(decoded, coded, strlen(message));
  printf("\n���������� ���������:\n%s", decoded);
  return 0;
}