/* Write a program to remove trailing blanks and tabs from each line
   of input, and to delete entirely blank lines. */
#include <stdio.h>

#define MAXLINE 1024

/* get_line: read a line into s, return length */
int get_line(char s[],int lim) {
  int c, i;

  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

/* this routine is not correct since the trailing blank may happen
   just before line truncate, and currently i don't have a graceful
   way to handle \w*[ \t]{m}\w+[ \t]{n}, since n may very large */
int main() {
  char line[MAXLINE];
  int len;

  while ((len = get_line(line, MAXLINE)) > 0) {
    len -= 2;
    while (len >= 0 && (line[len] == '\t' || line[len] == ' '))
      len--;
    if (len < 0)
      continue;
    line[len + 1] = '\n';
    line[len + 2] = '\0';
    printf("%s", line);
  }

  return 0;
}
