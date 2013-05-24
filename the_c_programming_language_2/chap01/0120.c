/* Write a program detab that replaces tabs in the input with the
   proper number of blanks to space to the next tab stop. Assume a
   fixed set of tab stops, say every n columns. Should n be a variable
   or a symbolic parameter? */
#include <stdio.h>

#define TABSTOP 8

int main() {
  char c;
  int i, pos;

  pos = 0;
  while ((c = getchar()) != EOF) {
    if ('\t' != c) {
      pos++;
      putchar(c);
      if ('\n' == c)
        pos = 0;
    } else {
      for (i = 0; i < TABSTOP - pos % TABSTOP; i++)
        putchar(' ');
      pos = pos + TABSTOP - pos % TABSTOP;
    }
  }

  return 0;
}
