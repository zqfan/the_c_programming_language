/* Write the function any(s1,s2), which returns the first location in
   a string s1 where any character from the string s2 occurs, or -1 if
   s1 contains no characters from s2. (The standard library function
   strpbrk does the same job but returns a pointer to the location.)
*/
#include <assert.h>

/* find the first location in string s1 where any character from
   string s2 occurs.
   i just loop two strings with O(M*N) cost, if s1 or s2 is very
   large, it can be optimized by make a 256 bool array indicates all
   ASCII character appearance in s2, which will reduce cost to O(M)
   + O(N)
*/
int any(const char s1[], const char s2[]) {
  int i, j;
  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
      ;
    if (s2[j] != '\0')
      return i;
  }
  if (s1[i] == '\0')
    return -1;
}

int main() {
  assert(any("abc", "cde") == 2);
  assert(any("abc", "bcd") == 1);
  assert(any("abc", "def") == -1);
  assert(any("abc", "") == -1);
  assert(any("", "abc") == -1);
  assert(any("", "") == -1);
  return 0;
}
