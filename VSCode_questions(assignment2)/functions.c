QUE 1 - (Find maximum of three integers)

#include <stdio.h>
int maxOfThree(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1; 
    }
    int result = maxOfThree(a, b, c);
    printf("%d\n", result);
    return 0;
}

QUE 2 - (Count multiples in range)

#include <stdio.h>
long long countMultiples(long long n, long long k) {
    if (k <= 0 || n <= 0) {
        return 0;
    }
    return n / k;
}

int main() {
    long long n, k;
    if (scanf("%lld %lld", &n, &k) != 2) {
        return 1; 
    }
    long long result = countMultiples(n, k);
    printf("%lld\n", result);

    return 0;
}

QUE 3 -(Rectangle area function)

#include <stdio.h>
long long calculateArea(long long length, long long width) {
    return length * width;
}
int main() {
    long long length, width;
    if (scanf("%lld %lld", &length, &width) != 2) {
        return 1; 
    }
    long long area = calculateArea(length, width);
    printf("%lld\n", area);
    return 0;
}

QUE 4 - (Perfect square without sqroot)

#include <stdio.h>
int isPerfectSquare(long long n) {
    if (n < 0) {
        return 0; 
    }
    if (n == 0 || n == 1) {
        return 1; 
    }

    long long left = 1;
    long long right = n / 2; 

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid == n / mid && n % mid == 0) {
            return 1; 
        } else if (mid < n / mid) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return 0;
}
int main() {
    long long n;
    if (scanf("%lld", &n) != 1) {
        return 1; 
    }
    printf("%d\n", isPerfectSquare(n));
    return 0;
}

QUE 5 - (GCD using Euclid's theorem)

#include <stdio.h>

static unsigned long long safe_abs(long long x) {
    return (x < 0) ? (0ULL - (unsigned long long)x) : (unsigned long long)x;
}

unsigned long long gcd(long long a, long long b) {
    unsigned long long x = safe_abs(a);
    unsigned long long y = safe_abs(b);

    while (y != 0) {
        unsigned long long rem = x % y;
        x = y;
        y = rem;
    }
    return x;
}

int main(void) {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2) {
        return 1;
    }

    printf("%llu\n", gcd(a, b));
    return 0;
}

QUE 6 - (Convert seconds)

#include <stdio.h>

int main(void) {
    long long totalSeconds;

    if (scanf("%lld", &totalSeconds) != 1) {
        return 1; // Handle invalid or missing input
    }

    long long hours = totalSeconds / 3600;
    long long remaining = totalSeconds % 3600;
    long long minutes = remaining / 60;
    long long seconds = remaining % 60;

    printf("%lld %lld %lld\n", hours, minutes, seconds);

    return 0;
}

QUE 7 - (Evaluate a piecewise function)

#include <stdio.h>

int main(void) {
    long long x;
    long long result;

    if (scanf("%lld", &x) != 1) {
        return 1; // Handle invalid or missing input
    }

    if (x < 0) {
        result = x * x + 2 * x + 1;
    } else if (x < 10) {
        result = 3 * x + 2;
    } else {
        result = 5 * x - 7;
    }

    printf("%lld\n", result);

    return 0;
}


