#include <stdio.h>

long long f[1000010];

long long gcd(long long a, long long b) {
    if (!a) return b;
    if (!b) return a;
    return (a>b?gcd(a%b,b):gcd(a,b%a));
}

void pre() {
    int i;
    f[0]=0; f[1]=1;
    for (i=2; i<=1000000; ++i)
	f[i]=(f[i-1]+f[i-2])%1000000007;
}

int main() {
    long long T, A, B;
    pre();
    scanf("%lld", &T);
    while (T--) {
	scanf("%lld %lld", &A, &B);
	printf("%lld\n", f[gcd(A,B)]);
    }
    return 0;
}
