#include <stdio.h>
#include <stdlib.h>

#define MAX       1000
#define NO_IND    (unsigned) (-1)
#define OPERATION <

const int x[MAX] = {0,8,3,5,7,0,8,9,10,20,20,20,12,19,11}; /* 0-��� �� �� ������ */
const unsigned n = 14; /* ���� */

unsigned Fmin[MAX];      /* ������ �������: ����. ������� �� ������, ���������� � ���������� */
unsigned Fmin_back[MAX]; /* �������� ������ �� �������� �� �������� ������� Fmin */
unsigned Fmax[MAX];      /* ������ �������: ����. ������� �� ������, ���������� � ���������� */
unsigned Fmax_back[MAX]; /* �������� ������ �� �������� �� �������� ������� Fmax */

void calculateFMinMax(void)
{ unsigned ind, ind2;
  /* ������������� */
  Fmin[0] = Fmax[0] = 1;
  Fmin_back[0] = Fmax_back[0] = NO_IND;
  /* �������������� ���������� �� ����� ������ ������� */
  for (ind = 1; ind < n; ind++) {
    Fmax_back[ind] = Fmin_back[ind] = NO_IND;
    Fmin[ind] = Fmax[ind] = 0;
    for (ind2 = 0; ind2 < ind; ind2++) {
      /* ���� �� ����������� �� ���������� ������ � ��������� ������� */
      if (x[ind2] OPERATION x[ind] && Fmin[ind2] > Fmax[ind]) {
        Fmax[ind] = Fmin[ind2];
        Fmax_back[ind] = ind2;
      }
      /* ���� �� ����������� �� ���������� ������ � ��������� ������� */
      if (x[ind] OPERATION x[ind2] && Fmax[ind2] > Fmin[ind]) {
        Fmin[ind] = Fmax[ind2];
        Fmin_back[ind] = ind2;
      }
    }
    /* ����������� � 1 ������ ������� ������� */
    Fmin[ind]++;
    Fmax[ind]++;
  }
}

void markSolutionElements(unsigned *f1, unsigned *f2, unsigned *fInd1,
                          unsigned *fInd2, unsigned indF)
{ if (NO_IND == fInd1[indF])
    return;
  f1[indF] = f2[indF] = NO_IND;
  markSolutionElements(f2, f1, fInd2, fInd1, fInd1[indF]);
}

void findSolution(void)
{ unsigned ind, bestFminInd, bestFmaxInd;
  /* �������� (����) �� ���-������� ������ */
  bestFminInd = bestFmaxInd = 0;
  for (ind = 1; ind < n; ind++) {
    if (Fmin[bestFminInd] < Fmin[ind])
	  bestFminInd = ind;
    if (Fmax[bestFmaxInd] < Fmax[ind])
	  bestFmaxInd = ind;
  }
  /* ��������� �� ���������� � */
  if (Fmin[bestFminInd] > Fmax[bestFmaxInd])
    markSolutionElements(Fmin, Fmax, Fmin_back, Fmax_back, bestFminInd);
  else
    markSolutionElements(Fmax, Fmin, Fmax_back, Fmin_back, bestFmaxInd);
  /* ��������� �� ��������� �� ������ */
  for (ind = 0; ind < n; ind++)
    if (NO_IND == Fmin[ind])
	  printf("%d ", x[ind]);
  printf("\n");
}

int main(void) {
  calculateFMinMax();
  findSolution();
  return 0;
}