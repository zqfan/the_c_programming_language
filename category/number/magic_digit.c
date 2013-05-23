#include <stdio.h>
#include <string.h>

void count_digits(int n, int * num) {
    while (n != 0) {
        num[n%10]++; /* get the last digit, and count it */
        n /= 10; /* it will be truncated */
    }
}

void main() {
    int i, j;
    int num[10];
    for (i = 123; i <= 329; i++) {
        memset((void *)num, 0, sizeof(num));
        count_digits(i, num);
        count_digits(i*2, num);
        count_digits(i*3, num);
        /* make sure all digits appear exactly one time */
        for (j = 1; j < 10 && 1 == num[j]; j++);
        /* find an answer */
        if (j == 10)
            printf("%d %d %d\n", i, i*2, i*3);
    }
}
