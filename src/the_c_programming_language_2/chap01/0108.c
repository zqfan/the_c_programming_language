/* Write a program to count blanks, tabs, and newlines. */
#include <stdio.h>

void main() {
  int c, nl, blk, tab;
  nl = blk = tab = 0;
  while ((c = getchar()) != EOF) {
    switch (c) {
    case ' ': ++blk; break;
    case '\t': ++tab; break;
    case '\n': ++nl; break;
    }
  }
  printf("blanks=%d, tabs=%d, newlines=%d\n", blk, tab, nl);
}
