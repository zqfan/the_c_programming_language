/* Write a function setbits(x,p,n,y) that returns x with the n bits
   that begin at position p set to the rightmost n bits of y, leaving
   the other bits unchanged.
*/
#include <assert.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  /* there is no enough bits for n, treat as wrong input */
  if (p + 1 < n)
    return x;
  unsigned t = ~(~0 << n) & y; /* get right n bits of y */
  t = t << (p + 1 - n); /* adjust to p */
  /* set target bits to zero, remain other bits */
  x = x & ((~0 << (p + 1)) | ~(~0 << (p + 1 - n)));
  return x | t;
}

int main() {
  assert(setbits(0xff, 3, 4, 0xaa) == 0xfa);
  /* wrong input */
  assert(setbits(0xff, 0, 4, 0xaa) == 0xff);
  assert(setbits(0xff, 0, 1, 0xaa) == 0xfe);
  assert(setbits(0xff, 3, 0, 0xaa) == 0xff);
  return 0;
}
