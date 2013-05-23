/* Write a program to print a histogram of the lengths of words in its
   input. It is easy to draw the histogram with the bars horizontal; a
   vertical orientation is more challenging. */
#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0
#define MAX_LEN 50 /* max length of word */

int main() {
  int c, i, j, k, state, len;
  /* lens[0] stores len which larger than MAX_LEN */
  int lens[MAX_LEN+1];
  memset((void *)lens, 0, sizeof(lens));
  state = OUT;
  len = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      state = IN;
      len++;
    } else if (IN == state) {
      state = OUT;
      len <= MAX_LEN ? lens[len]++ : lens[0]++;
      len = 0;
    }
  }
  /* ignore the empty large len */
  for (k = MAX_LEN; k >= 0 && lens[k] == 0; k--);
  /* draw histogram horizontal */
  for (i = 0; i <= k && lens[i] == 0; i++);
  for (; i <= k; i++) {
    printf("%2d ", i);
    for (j = 0; j < lens[i]; j++)
      printf("#");
    printf(" %d\n", lens[i]);
  }
  /* draw histogram vertical */
  for (i = 0; i <= k && lens[i] == 0; i++);
  for (j = i; j <= k; j++)
    printf("%2d ", j); /* draw head */
  printf("\n");
  while (1) {
    len = 0;
    for (j = i; j <= k; j++) {
      if (lens[j] != 0) {
        len += --lens[j];
        printf(" # ");
      } else {
        printf("   ");
      }
    } /* end for */
    printf("\n");
    if (len == 0)
      break;
  } /* end while */
  return 0;
}

