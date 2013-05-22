/* Write a program to copy its input to its output, replacing each
   string of one or more blanks by a single blank. */
#include <stdio.h>

void main() {
  int c, blk;
  blk = 0;
  while ((c = getchar()) != EOF) {
    c == ' ' ? ++blk : (blk = 0);
    if (blk <= 1)
      putchar(c);
  }
}
