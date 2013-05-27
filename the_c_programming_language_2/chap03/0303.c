/* Write a function expand(s1,s2) that expands shorthand notations
   like a-z in the string s1 into the equivalent complete list
   abc...xyz in s2. Allow for letters of either case and digits, and
   be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
   that a leading or trailing - is taken literally. */
#include <stdio.h>
#include <assert.h>

/* expand - to complete list, s2 should have enough space */
void expand(const char * s1, char * s2) {
  char prev;
  int i, j, k, same_range;
  prev = 0;
  for (i = j = 0; s1[i] != 0; i++) {
    if (s1[i] != '-')
      prev = s2[j++] = s1[i];
    else {
      if (prev == 0) {
        s2[j++] = '-';
        continue;
      }
      if (s1[i+1] == 0) { // end of s1
        s2[j++] = '-';
        break;
      }
      same_range = 0;
      if ('a' <= prev && prev <= 'z' &&
          'a' <= s1[i+1] && s1[i+1] <= 'z')
        same_range = 1;
      else if ('A' <= prev && prev <= 'Z' &&
               'A' <= s1[i+1] && s1[i+1] <= 'Z')
        same_range = 1;
      else if ('0' <= prev && prev <= '9' &&
               '0' <= s1[i+1] && s1[i+1] <= '9')
        same_range = 1;
      if (same_range && s1[i+1] > prev) {
        for (k = prev + 1; k < s1[i+1]; k++)
          s2[j++] = k;
      } else {
        s2[j++] = '-';
        prev = '-';
      }
    } // end else if (prev!=0)
  } // end for i
  s2[j] = 0;
}

int main() {
  char s2[100];
  expand("---a-c0-2a-c-ea-aa-CA-ca-92-0a---", s2);
  assert(strcmp(s2, "---abc012abcdea-aa-CA-ca-92-0a---") == 0);
  return 0;
}
