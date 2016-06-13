#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S 107           /* ������ �� ����������� ��� ������� */
unsigned long n = 32;   /* ������� ������ �� ���-��������� */

struct singleWord {
  char *word;           /* ���� - �������� ��� */
  unsigned long freq;   /* ������� �� ������� �� ������ */
} *ht;

unsigned long count;

/* ���-������� �� �������� ��� */
unsigned long hashFunction(const char *key)
{ unsigned long result = 0;
  while (*key)
    result += result + (unsigned char) *key++;
  return result & (n - 1);
}

/* �������������� �� ���-��������� */
void initHashtable(void)
{ unsigned long i;
  count = 0;
  ht = (struct singleWord *) malloc(sizeof(*ht)*n);
  for (i = 0; i < n; i++)
    ht[i].word = NULL;
}

/* ������� � ���-���������: ����� 1 ��� �����, � 0 � ����� */
/* ��� �����: *ind ������� ������� �� ��������� ������� */
/* ��� �������: �������� �������, ������ ���� �� ���� ������� */
char get(const char *key, unsigned long *ind)
{ unsigned long k;
  *ind = hashFunction(key);
  k = *ind;
  do {
    if (NULL == ht[*ind].word) return 0;
    if (0 == strcmp(key, ht[*ind].word)) return 1;
    *ind = (*ind + S) & (n - 1);
  } while (*ind != k);
  return 0;
}

/* ����������� �� ���-��������� */
void resize(void)
{ unsigned long ind, hashInd;
  struct singleWord *oldHashTable;

  /* 1. ��������� �� �������� ��� ���-��������� */
  oldHashTable = ht;

  /* 2. ������ ����������� */
  n <<= 1;

  /* 3. �������� �� ����� �� ������ ���-������� */
  ht = (struct singleWord *) malloc(sizeof(*ht)*n);
  for (ind = 0; ind < n; ind++)
    ht[ind].word = NULL;

  /* 4. ����������� �� �������� � ������ ���-������� */
  for (ind = 0; ind < (n >> 1); ind++) {
    if (oldHashTable[ind].word != NULL) {
      /* ��������� ������ �� ������ ����� */
      if (!get(oldHashTable[ind].word, &hashInd))
        ht[hashInd] = oldHashTable[ind];
      else
        printf("������ ��� ����������� �� ���-���������!\n");
    }
  }

  /* 5. ������������� �� ������� ����� */
  free(oldHashTable);
}

/* �������� �� ������� � ���-��������� */
void put(char *key)
{ unsigned long ind;
  if (!get(key, &ind)) { /* ������ �� � � ���-��������� */
    ht[ind].word = strdup(key);
    ht[ind].freq = 1;
    if (++count > ((unsigned long) n * 0.9)) resize();
  }
  else
    ht[ind].freq++;
}

/* ����������� �� ���-������� */
void printAll(void)
{ unsigned long ind;
  for (ind = 0; ind < n; ind++)
    if (ht[ind].word != NULL)
	  printf("%s %ld \n", ht[ind].word, ht[ind].freq);
}

/* ����������� �� ���-������� */
void destroy(void)
{ unsigned long ind;
  for (ind = 0; ind < n; ind++)
    if (ht[ind].word != NULL) free(ht[ind].word);
  free(ht);
}

int main(void) {
  unsigned long find;
  initHashtable();

  put("reload");
  put("crush tour");
  put("room service");
  put("load");
  put("reload");
  put("reload");

  printAll();

  if (get("reload", &find))
    printf("������� �� ������ 'reload': %d \n", ht[find].freq);
  else
	printf("������ 'reload' ������!");

  if (get("download", &find))
    printf("������� �� ������ 'download': %d \n", ht[find].freq);
  else
	printf("������ 'download' ������!");

  destroy();
  return 0;
}
