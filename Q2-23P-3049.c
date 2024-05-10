#include <stdio.h>

int collatzLength(long long num) {
    int len = 1;
    while (num != 1) {
        if (num % 2 == 0)
            num = num / 2;
        else
            num = 3 * num + 1;
        len++;
    }
    return len;
}

void longestCollatz(long long limit) {
    long long longestStart = 0;
    int maxLen = 0;
    long long i;
    for (i = 2; i < limit; i++) {
        int len = collatzLength(i);
        if (len > maxLen) {
            maxLen = len;
            longestStart = i;
        }
    }
    
    printf("Number with the longest Collatz sequence under %lld is %lld, with a length of %d.\n", limit, longestStart, maxLen);
}

int main() {
    long long limit;
    printf("Enter the upper limit: ");
    scanf("%lld", &limit);

    longestCollatz(limit);
    
    return 0;
}

