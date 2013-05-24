/* Write a function escape(s,t) that converts characters like newline
   and tab into visible escape sequences like \n and \t as it copies
   the string t to s. Use a switch. Write a function for the other
   direction as well, converting escape sequences into the real
   characters. */
#include <stdio.h>

/* copy t to s, escape unprintable characters, make sure s has enough
   space */
void escape(char * s, const char * t) {
  int i, j;
  for (i = 0, j = 0; t[i] != '\0'; i++) {
    switch (t[i]) {
    case '\n': s[j++] = '\\'; s[j++] = 'n'; break;
    case '\t': s[j++] = '\\'; s[j++] = 't'; break;
    case '\a': s[j++] = '\\'; s[j++] = 'a'; break;
    case '\r': s[j++] = '\\'; s[j++] = 'r'; break;
    case '\v': s[j++] = '\\'; s[j++] = 'v'; break;
    case '\b': s[j++] = '\\'; s[j++] = 'b'; break;
    default: s[j++] = t[i]; break;
    }
  }
  s[j] = '\0';
}

/* copy t to s, convert escape string to real characters, make sure s
   has enough space */
void unescape(char * s, const char * t) {
  int slash = 0;
  int i, j;
  for (i = j = 0; t[i] != '\0'; i++) {
    if (slash) {
      slash = 0;
      switch(t[i]) {
      case 'n': s[j++] = '\n'; break;
      case 't': s[j++] = '\t'; break;
      case 'a': s[j++] = '\a'; break;
      case 'r': s[j++] = '\r'; break;
      case 'v': s[j++] = '\v'; break;
      case 'b': s[j++] = '\b'; break;
      default: s[j++] = t[i];
      }
    } else if (t[i] == '\\')
      slash = 1;
    else
      s[j++] = t[i];
  }
  s[j] = '\0';
}

int main() {
  char s[16];
  char t1[16] = "a\t\n\a";
  escape(s, t1);
  printf("%s\n", s);
  char t2[16] = "a\\t\\n\\ab";
  unescape(s, t2);
  printf("%s\n", s);
  return 0;
}
