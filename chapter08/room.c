#include <stdio.h>
#define MAXN  5000  /* ���������� ���� ������ */
#define MAXD  365   /* ���������� ���� ��� */
struct TZ { unsigned b, e; };

struct { unsigned cntBlue, cntRed; } B[MAXD], R[MAXD];

const unsigned n = 2; /* ���� ���� ������ */
const unsigned m = 4; /* ���� ������� ������ */
struct TZ blueOrders[MAXN] = { {1,5}, {12,20} };
struct TZ redOrders[MAXN] = { {2,10}, {6,11}, {15,25}, {26,30} };

/* ������� �������� */
void sort(struct TZ Z[], const unsigned count)
{ unsigned i, j;
  struct TZ swp;
  for (i = 0; i < count; i++)
    for (j = i + 1; j < count; j++)
      if (Z[i].e > Z[j].e) {
        swp = Z[i];
		Z[i] = Z[j];
		Z[j] = swp;
      }
}

/* ������ �������� � ��������� ���������� */
void solveDynamic(void)
{ unsigned d, bb, be, blueIndex, redIndex;
  /* ������������� */
  B[0].cntBlue = B[0].cntRed = R[0].cntBlue = R[0].cntRed = 0; 
  blueIndex = redIndex = 1;
  /* ���������� �� B[1..MAXD], R[1..MAXD] */
  for (d = 1; d <= MAXD; d++) {
    /* ���������� �� B[d] */
    B[d] = B[d - 1];
    for (blueIndex = 0; blueIndex < n; blueIndex++) {
      if (blueOrders[blueIndex].e > d)
        break;
      else {
        bb = blueOrders[blueIndex].b;
        be = blueOrders[blueIndex].e;
        if (R[bb-1].cntBlue + R[bb-1].cntRed + (be-bb+1) > B[d].cntBlue + B[d].cntRed) {
          B[d].cntBlue = R[bb - 1].cntBlue + (be - bb + 1);
          B[d].cntRed = R[bb - 1].cntRed + 0;
        }
      }
    }
    /* ���������� �� R[d]: ���������� �� B[d] */
    R[d] = R[d - 1];
    for (redIndex = 0; redIndex < m; redIndex++) {
      if (redOrders[redIndex].e > d)
        break;
      else {
        bb = redOrders[redIndex].b;
        be = redOrders[redIndex].e;
        if (B[bb-1].cntBlue + B[bb-1].cntRed + (be-bb+1) > R[d].cntBlue + R[d].cntRed) {
          R[d].cntBlue = B[bb - 1].cntBlue;
          R[d].cntRed = B[bb - 1].cntRed + (be - bb + 1);
        }
      }
    }
  }
}

/* ������� ��������� �� ������ */
void printResult(void)
{ if (B[MAXD].cntBlue + B[MAXD].cntRed > R[MAXD].cntBlue + R[MAXD].cntRed) {
    printf("\n������� �� ������ (���): %u", B[MAXD].cntBlue + B[MAXD].cntRed);
    printf("\n���� ��� �� ���������: %u", B[MAXD].cntRed);
    printf("\n���� ��� �� ������: %u", B[MAXD].cntBlue);
  }
  else {
    printf("\n������� �� ������ (���): %u", R[MAXD].cntBlue + R[MAXD].cntRed);
    printf("\n���� ��� �� ���������: %u", R[MAXD].cntRed);
    printf("\n���� ��� �� ������: %u", R[MAXD].cntBlue);
  }
}

int main(void) {
  sort(blueOrders, n);
  sort(redOrders, m);
  solveDynamic();
  printResult();
  return 0;
}