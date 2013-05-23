/* Write a program to print all input lines that are longer than 80
   characters. */
#include <stdio.h>

#define MAXLINE 81

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

int main() {
  char line[MAXLINE];
  int len, is_continuous;

  is_continuous = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (is_continuous)
      printf("%s", line);
    /* it is a very long line */
    if ((MAXLINE == len + 1) && (line[MAXLINE-2] != '\n')) {
      /* it is not printed before, then should be printed here */
      if (!is_continuous)
        printf("%s", line);
      is_continuous = 1;
    } else
      is_continuous = 0;
  }
  return 0;
}
