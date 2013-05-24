/* Write a function reverse(s) that reverses the character string s.
   Use it to write a program that reverses its input a line at a time.
*/
#include <stdio.h>

#define MAXLINE 1024

/* reverse string s, NOTE s should terminated with \n\0 */
char * reverse(char s[]) {
  int i, j, tmp;
  for (i = 0; s[i] != '\0'; i++);
  for (j = 0, i -= 2; j < i; j++, i--) {
    tmp = s[j];
    s[j] = s[i];
    s[i] = tmp;
  }
  return s;
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

int main() {
  char line[MAXLINE];
  int len;
  while ((len = get_line(line, MAXLINE)) > 0)
    printf("%s", reverse(line));
  return 0;
}
