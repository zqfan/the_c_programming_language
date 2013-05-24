/* Write a program entab that replaces strings of blanks by the
   minimum number of tabs and blanks to achieve the same spacing. Use
   the same tab stops as for detab. When either a tab or a single
   blank would suffice to reach a tab stop, which should be given
   preference? */
#include <stdio.h>

#define TABSTOP 8

int main() {
  char c;
  int col, blanks, tabs, i;

  col = blanks = 0;
  while ((c = getchar()) != EOF) {
    if (' ' == c) {
      col++;
      blanks++;
    } else {
      if (blanks == 1)
        putchar(' ');
      else if (blanks > 1) {
        tabs = col/TABSTOP - (col - blanks)/TABSTOP;
        for (i = 0; i < tabs; i++)
          putchar('\t');
        if (tabs > 0) /* there is a tab, then reduce blanks */
          blanks = col % TABSTOP;
        for (i = 0; i < blanks; i++)
          putchar(' ');
      }
      putchar(c);
      col++;
      blanks = 0;
      if ('\n' == c)
        col = 0;
    }
  }

  return 0;
}
