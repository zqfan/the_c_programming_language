/* Write a function htoi(s), which converts a string of hexadecimal
   digits (including an optional 0x or 0X) into its equivalent integer
   value. The allowable digits are 0 through 9, a through f, and A
   through F. */
#include<stdio.h>
#include<assert.h>

/* convert or truncate string s of hexadecimal digits into integer */
int htoi(const char * s) {
  int i = 0;
  /* start with 0 */
  if (s[0] != 0 && s[0] == '0') {
    if (s[1] == 0)
      return 0;
    /* not start with 0x nor 0X */
    if (s[1] != 'x' && s[1] != 'X')
      return 0;
    i = 2;
  }
  int r = 0;
  while (s[i] != 0) {
    if (isdigit(s[i]))
      r = r * 16 + s[i] - '0';
    else if ('a' <= s[i] && s[i] <= 'f')
      r = r * 16 + s[i] - 'a' + 10;
    else if ('A' <= s[i] && s[i] <= 'F')
      r = r * 16 + s[i] - 'A' + 10;
    /* truncate wrong input and return the value */
    else
      return r;
    i++;
  }
  return r;
}

int main() {
  /* empty will be treated as zero, which perhaps means false */
  assert(0 == htoi(""));
  assert(0 == htoi("0"));
  assert(0 == htoi("0x"));
  assert(0 == htoi("x"));
  assert(0x123 == htoi("123"));
  assert(0x1f == htoi("1f"));
  assert(0xa0 == htoi("0xa0"));
  assert(0xa0 == htoi("0XA0"));
  /* wrong input will be truncated */
  assert(0xa0 == htoi("a0hell"));
  assert(0xa0 == htoi("0xa0hell"));
  return 0;
}
