/* ��������� �� ������ */
for (i = 0; i < m; i++)
  for (j = 0; j < n; j++) scanf("%d", &A[i][j]);

/* ��������� �� �������� */
for (i = 0; i < m; i++)
  for (j = 0; j < n; j++) scanf("%d", &A[j][i]);

/* ����������� �� ������� �� ������ */
for (i = 0; i < m; i++) {
  for (j = 0; j < n; j++) printf("%.3d", A[i][j]);
  printf("\n");
}
