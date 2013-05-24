/* Our binary search makes two tests inside the loop, when one would
   suffice (at the price of more tests outside.) Write a version with
   only one test inside the loop and measure the difference in
   run-time. */
#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low < high) {
    /* make sure mid will choose high if they are next to each */
    mid = (low+high+1)/2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid;
  }
  return x == v[low] ? low : -1;
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6};
  printf("%d\n", binsearch(2, a, 6));
  return 0;
}
