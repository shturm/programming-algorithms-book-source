unsigned n = 4242;

int main(void) {
  unsigned digits;
  for (digits = 0; n > 0; n /= 10, digits++);
  printf("����� �� ������� �� %u � %u\n", n, digits);
  return 0;
}
