#include <stdio.h>
#include <string.h>

int main() {
  char a[] = "1111";
  char b[] = "1110";

  int al = strlen(a) - 1;
  int bl = strlen(b) - 1;

  int count = 0, sum = 0, k = 0, carry = 0;
  char result[(strlen(a) > strlen(b) ? strlen(a) : strlen(b)) + 2];

  while (al >= 0 || bl >= 0 || carry > 0) {
    sum = carry;

    if (al >= 0)
      sum += a[al] - '0';
    if (bl >= 0)
      sum += b[bl] - '0';

    int digit = sum % 2;
    int carry = sum / 2;

    result[k++] = digit + '0';

    al--;
    bl--;
  }

  result[k++] = '\0';

  for (int i = k; i >= 0; i--) {
    printf("%c", result[i]);
  }
}
