/* In a two's complement number system, x &= (x-1) deletes the
   rightmost 1-bit in x. Explain why. Use this observation to write a
   faster version of bitcount.
*/
/* assume the rightmost 1-bit in x position i, x-1 will cause i-th bit
   to 0, all bits in the right of i is change to 1, all bits in the
   left of i will remain, so x &= (x-1) will just remain all bits in
   the left of i, and set else to 0.
*/
#include <assert.h>

unsigned bitcount(unsigned x) {
  unsigned count = 0;
  while (x != 0) {
    ++count;
    x &= (x-1);
  }
  return count;
}

int main() {
  assert(bitcount(0xff) == 8);
  assert(bitcount(0x11) == 2);
  assert(bitcount(0) == 0);
  return 0;
}
