/* Write a function invert(x,p,n) that returns x with the n bits that
   begin at position p inverted (i.e., 1 changed into 0 and vice
   versa), leaving the others unchanged.
*/
#include <assert.h>

unsigned invert(unsigned x, int p, int n) {
  /* there is no enough bits for n, treat as wrong input */
  if (p + 1 < n)
    return x;
  /* get p+1-n bits of 0 adjust to p */
  unsigned t = (~0 << (p + 1)) | ~(~0 << (p + 1 - n));
  return (~(x & ~t) & ~t) | (x & t);
}

int main() {
  assert(invert(0xff, 3, 2) == 0xf3);
  assert(invert(0xff, 3, 4) == 0xf0);
  assert(invert(0xff, 3, 0) == 0xff);
  assert(invert(0xff, 0, 4) == 0xff);
  return 0;
}
