#include <stdio.h>
#include <stdlib.h>

#define MAX 256
#define MSG "afbabcdefacbabcdecde"

struct tree {
  char sym;                  /* ������ */
  struct tree *left, *right; /* ��� � ����� ���������� */
};

struct CForest {
  unsigned weight;           /* ����� �� ������� */
  struct tree *root;         /* ������� */
} forest[MAX];               /* ����: ����� �� ������� */

unsigned treeCnt;            /* ���� ������� � ������ */
char code[MAX];              /* ��� �� ������ �� ���������� ������ */

/***********************************************************/
/************** ������� �� ������ � �������� ***************/
/***********************************************************/

void siftUp(unsigned k) /* "������" ������� ������ �� ���������� */
{ struct CForest save = forest[k]; /* ������� ���������� */
  unsigned parent = k/2;           /* "����" �� ������������ ������� */
  while (parent >= 1) {
    if (save.weight < forest[parent].weight) { /* ����������� ��� ����� �� ���������� */
      forest[k] = forest[parent];
      k = parent;
    }
    parent /= 2;
  }
  forest[k] = save; /* �������� � ������������� ����� �� �������� */
}

void siftDown(void) /* "������" ������� ������ �� ���������� */
{ unsigned parent = 1,         /* "����" */
           child  = 2;         /* "����" */
  struct CForest save = forest[1]; /* ������� ���������� */
  while (child <= treeCnt) {
    if (child+1 <= treeCnt) /* ������� �� ��-������� ��������� */
      if (forest[child+1].weight < forest[child].weight)
        child++;
    if (save.weight > forest[child].weight) { /* �������� �� �������� ������ */
      forest[parent] = forest[child];
      parent = child;
      child *= 2;
    }
    else
      break;
  }
  forest[parent] = save; /* �������� � ������������� ����� �� �������� */
}

void removeMin(void) /* �������� ����� �� ���������� */
{ forest[1] = forest[treeCnt--];
  siftDown();
}

/*********************************************/
/************* ������� �������� **************/
/*********************************************/

void initModel(char *msg)   /* ������ ��������� �� ������� �� ��������� */
{ char *c = msg;
  unsigned freqs[MAX]; /* ������� �� ������� �� ��������� */
  unsigned i;

  /* ����������� ������� �� ��������� �� ������� */
  for (i = 0; i < MAX; i++)
    freqs[i] = 0;
  while (*c)
    freqs[(unsigned char) *c++]++;

  /* �� ����� ������ � �������� ������� �� ������� ��������� ��������� ����� */
  treeCnt = 0;
  for (i = 0; i < MAX; i++)
    if (freqs[i]) {
      forest[++treeCnt].weight = freqs[i];
      forest[treeCnt].root = (struct tree *) malloc(sizeof(struct tree));
      forest[treeCnt].root->left = NULL;
      forest[treeCnt].root->right = NULL;
      forest[treeCnt].root->sym = i;
      siftUp(treeCnt);
    }
}

void huffman(void)
{ struct CForest min1, min2;
  while (treeCnt > 1) {
    /* �������� � ���������� �� ����� ���-���� ����� */
    min1 = forest[1];
    removeMin();
    min2 = forest[1];
    removeMin();
    /* ��������� �� ��� ����� - ���������� �� ����� ���-����� */
    forest[++treeCnt].root = (struct tree *) malloc(sizeof(struct tree));
    forest[treeCnt].root->left = min1.root;
    forest[treeCnt].root->right = min2.root;
    forest[treeCnt].weight = min1.weight + min2.weight;
    /* �������� �� ������ */
    siftUp(treeCnt);
  }
}

void printTree(struct tree *t, unsigned h)
/* ������� ������� �� ������, ����� ���� �������� ������� �� */
{ unsigned i;
  if (NULL != t) {
    printTree(t->left,h+1);
    for (i = 0; i < h; i++)
      printf("   ");
    printf(" -- ");
    if (NULL == t->left)
      printf(" %c", t->sym);
    printf("\n");
    printTree(t->right,h+1);
  }
}

void writeCodes(struct tree *t, unsigned index) /* ������� �������� */
{ if (NULL != t) {
    code[index] = '0';
    writeCodes(t->left,index+1);
    if (NULL == t->left) { /* ����� ���� �� ����. ����� ��� 0 ��� 2 ���������� */
      code[index] = '\0';
      printf("%c = %s\n",t->sym,code);
    }
    code[index] = '1';
    writeCodes(t->right,index+1);
  }
}

int main(void) {
  initModel(MSG);
  huffman();
  printf("����� �� ������ �� %s:\n",MSG);
  printTree(forest[1].root,0);
  writeCodes(forest[1].root,0);
  return 0;
}