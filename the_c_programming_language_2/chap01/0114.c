/* Write a program to print a histogram of the frequencies of
   different characters in its input. */
#include <stdio.h>

#define RANGE 128 /* ASCII code */

int main() {
  int freq[RANGE] = {0};
  int i, j, c, count;
  float f;
  while ((c = getchar()) != EOF)
    freq[c]++;
  for (i = 0, count = 0; i < RANGE; i++)
    count += freq[i];
  for (i = 0; i < RANGE; i++) {
    switch (i) {
    case '\b': printf("\\b: "); break;
    case '\t': printf("\\t: "); break;
    case '\n': printf("\\n: "); break;
    default: printf(" %c: ", i);
    }
    f = freq[i] * 100.0 / count;
    printf("%4.2f%% ", f);
    for (j = 0; j < (int)f; j++)
      printf("#");
    printf("\n");
  }
  return 0;
}
