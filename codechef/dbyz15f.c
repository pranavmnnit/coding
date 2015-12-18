#include <stdio.h>

inline int gcd(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    return (a > b ? gcd(a%b, b) : gcd(a, b%a));
}

int main() {
    int k;
    int i;
    int arr[1010];
    long long n;
    scanf("%d %lld", &k, &n);
    for (i = 0; i < k; ++i) {
	scanf("%d", arr+i);
    }

    if (k == 1) {
	printf("%lld\n", (n * k)); return 0;
    }

    long long lcm = (1LL * arr[0] * arr[1])/(gcd(arr[0], arr[1]));
    for (i = 2; i < k; ++i) {
	lcm = (lcm * arr[i])/(gcd(arr[i], lcm));
	printf("i = %d, lcm = %lld\n", i, lcm);
    }

    long long num = 0;
    for (i = 0; i < k; ++i) {
	num += (lcm / arr[i]);
    }

    printf("%lld\n", (n * lcm)/(num));

    return 0;
}
