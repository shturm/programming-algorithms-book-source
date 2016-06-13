#define EPS 0.0001
#define MAX_LEN 100

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char getChar(char n) /* ����� �������, ������������ �� n */
{  return (n < 10) ? n + '0' : n + 'A' - 10; }

char getValue(char c) /* ����� ���������� �� ������� c */
{  return (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10; }

void reverse(char *pch)
{ char *pEnd;
  for (pEnd = pch + strlen(pch) - 1; pch < pEnd; pch++, pEnd--) {
	char c = *pch;
	*pch = *pEnd;
	*pEnd = c;
  }
}

void convert(char *rslt, unsigned long n, unsigned char base)
/* ����������� ������ ��������� ����� n (n >= 0) � ������ ������� � ������ base */
{ char *saveRslt = rslt;
  while (n > 0) {
	*rslt++ = getChar((char)(n % base));
	n /= base;
  }
  *rslt = '\0';
  reverse(saveRslt);
}

void convertLessThan1(char *rslt, double n, unsigned char base, unsigned char cnt)
/* ����������� ����������� ����� 0 <= n < 1 � ������ ������� � ������ base
   � �� ������ �� cnt �� ���� ����� ���� ����������� ������� */
{ 
  while (cnt--) {
    /* ���� �� ��� �������� 0? */
	if (fabs(n) < EPS) break;
	/* ���������� �� ���������� ����� */
    n *= base;
	*rslt++ = getChar((char)(int)floor(n));
    n -= floor(n);
  }
  *rslt = '\0';
}

void convertReal(char *rslt, double n, unsigned char base, unsigned char cnt)
  /* ����������� ����������� ������ ����� n � ������ ������� � ������ base */
{ double integer, fraction;

  /* �������� �� ����� */
  if (n < 0) {
	*rslt++ = '-';
	n = -n;
  }

  /* ��������� �� ���� � ������ ���� */
  fraction = modf(n, &integer); 

  /* ������������ �� ������ ���� */
  convert(rslt, (unsigned long)integer, base);

  /* ��������� �� ��������� ����� */
  if ('\0' == *rslt)
	*rslt++ = '0';
  else
	rslt += strlen(rslt);
  *rslt++ = '.';

  /* ������������ �� �������� ���� */
  convertLessThan1(rslt, fraction, base, cnt);
  if ('\0' == *rslt) {
	*rslt++ = '0';
	*rslt = '\0';
  }
}

unsigned long calculate(const char *numb, unsigned char base)
/* ������ ����������� �������� �� ������� numb, �������� � ������ �������
    � ������ base, numb >= 0 */
{ unsigned long result;
  for (result = 0; '\0' != *numb; numb++)
    result = result*base + getValue(*numb);
  return result;
}

double calculateLessThan1(const char *numb, unsigned char base)
/* ������ ����������� �������� �� ������� numb (0 < numb < 1),
   �������� � ������ ������� � ������ base */
{ const char *end;
  double result;
  for (end = numb + strlen(numb) - 1, result = 0.0; end >= numb; end--)
    result = (result + getValue(*end)) / base;
  return result;
}

double calculateReal(char *numb, unsigned char base)
/* ������ ����������� �������� �� �������� ����� numb, ��������
   � ������ ������� � ������ base */
{ char *pointPos;
  char minus;
  double result;

  /* �������� �� ����� */
  if ('-' == *numb) {
	minus = -1;
	numb++;
  }
  else
	minus = 1;

  if (NULL == (pointPos = strchr(numb, '.')))
    return calculate(numb, base); /* ���� ������ ���� */
  
  /* ���������� �� ������ ���� */
  *pointPos = '\0';
  result = calculate(numb, base);
  *pointPos = '.';

  /* ��������� �� �������� ���� */
  result += calculateLessThan1(pointPos+1, base);

  return minus*result;

}

int main(void) {
  char numb[MAX_LEN];
  printf("!!! ������������ �� ��������������� ����� ������ ������� !!!\n");
  convertReal(numb, 777.777, 7, 10); printf("���������� ����� �� 777.777 (10) � %s\n", numb);
  strcpy(numb,"11.D873");
  printf("����������� ����� �� 11.D873 (16) �: %0.10lf\n",calculateReal(numb,16));
  return 0;
}