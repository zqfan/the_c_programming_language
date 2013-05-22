/* Write a function rightrot(x,n) that returns the value of the
   integer x rotated to the right by n positions.
*/
#include <assert.h>

unsigned rightrot(unsigned x, int n) {
  int i;
  for (i = 0; i < n; i++)
    x = (x >> 1) | (x << (sizeof(x) * 8 - 1));
  return x;
}

int main() {
  assert(rightrot(0, 3) == 0);
  assert(rightrot(0xff, 0) == 0xff);
  /* in my computer, sizeof(unsigned) == 4 */
  assert(rightrot(0xff, 4) == 0xf000000f);
  assert(rightrot(0xff, 3) == 0xe000001f);
  return 0;
}
