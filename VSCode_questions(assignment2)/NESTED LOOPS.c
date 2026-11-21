NESTED LOOPS 

QUE 1 - (Count pairs with a target sum)

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long target;

    if (scanf("%d %lld", &n, &target) != 2) {
        return 1; // Handle invalid or missing input
    }

    if (n < 2) {
        // Consume any single remaining element if n == 1, then output 0
        printf("0\n");
        return 0;
    }

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (arr == NULL) {
        return 1; // Handle allocation failure
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    long long count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                count++;
            }
        }
    }

    printf("%lld\n", count);

    free(arr);
    return 0;
}

QUE 2 - (Count relatively prime values)

#include <stdio.h>

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(void) {
    long long n, m;

    if (scanf("%lld %lld", &n, &m) != 2) {
        return 1; // Handle invalid or missing input
    }

    long long count = 0;
    for (long long x = 1; x <= m; x++) {
        if (gcd(x, n) == 1) {
            count++;
        }
    }

    printf("%lld\n", count);

    return 0;
}

QUE 3 - (Pythagorean triples upto N )

#include <stdio.h>

int main(void) {
    long long n;

    if (scanf("%lld", &n) != 1) {
        return 1; // Handle invalid or missing input
    }

    int found = 0;

    for (long long a = 1; a <= n; a++) {
        long long c = a + 2;
        for (long long b = a + 1; b < n; b++) {
            long long sumSq = a * a + b * b;

            while (c <= n && c * c < sumSq) {
                c++;
            }

            if (c > n) {
                break; // Larger b will only produce larger c > n
            }

            if (c * c == sumSq) {
                printf("%lld %lld %lld\n", a, b, c);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("None\n");
    }

    return 0;
}


QUE 4 - (Pairs with equal digit sum)

#include <stdio.h>

int digitSum(long long x) {
    unsigned long long val = (x < 0) ? -(unsigned long long)x : (unsigned long long)x;
    int sum = 0;
    while (val > 0) {
        sum += (int)(val % 10);
        val /= 10;
    }
    return sum;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1; // Handle invalid or missing input
    }

    if (n < 2) {
        printf("0\n");
        return 0;
    }

    // Maximum digit sum for a 64-bit integer (up to 19 digits) is 171
    long long freq[200] = {0};
    long long pairs = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        if (scanf("%lld", &x) != 1) {
            return 1;
        }
        int s = digitSum(x);
        pairs += freq[s];
        freq[s]++;
    }

    printf("%lld\n", pairs);

    return 0;
}

QUE 5  - (Closest pair difference)

#include <stdio.h>

long long abs_diff(long long a, long long b) {
    return (a > b) ? (a - b) : (b - a);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) {
        return 1;
    }

    long long arr[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &arr[i]) != 1) {
            return 1;
        }
    }

    long long min_diff = abs_diff(arr[0], arr[1]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = abs_diff(arr[i], arr[j]);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
    }

    printf("%lld\n", min_diff);
    return 0;
}

