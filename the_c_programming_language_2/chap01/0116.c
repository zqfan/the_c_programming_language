/* Revise the main routine of the longest-line program so it will
   correctly print the length of arbitrary long input lines, and as
   much as possible of the text. */
#include <stdio.h>

#define MAXLINE 10 /* maximum input line length */
#define IN 1
#define OUT 0

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
  int len;                 /* current line length */
  int max;                 /* maximum length seen so far */
  char line[MAXLINE];      /* current input line */
  char longest[MAXLINE];   /* longest line saved here */
  char buffer[MAXLINE];    /* current input line's first part */
  int state, read_len;

  max = len = 0;
  state = OUT;
  while ((read_len = get_line(line, MAXLINE)) > 0) {
    len += read_len;
    /* copy the first part if meet new line */
    if (OUT == state)
        copy(buffer, line);
    /* find a very long line */
    if (read_len == MAXLINE - 1 && line[MAXLINE - 2] != '\n')
      state = IN;
    else
      state = OUT;
    if (OUT == state && len > max) {
      max = len;
      copy(longest, buffer);
    }
    if (OUT == state)
      len = 0;
  }
  if (max > 0) /* there was a line */
    printf("%d %s", max, longest);
  if (max > MAXLINE)
    printf("\n");
  return 0;
}

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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
