/* Rewrite the function lower, which converts upper case letters to
   lower case, with a conditional expression instead of if-else.
*/
#include <assert.h>

/* lower character c if it can be lower */
int lower(int c) {
  return 'A' <= c && c <= 'Z' ? 'a' + c - 'A' : c;
}

int main() {
  assert(lower('A') == 'a');
  assert(lower('Z') == 'z');
  assert(lower('X') == 'x');
  assert(lower('~') == '~');
  return 0;
}
