#include <iostream>
#include <cstring>
#define ull unsigned long long
#define ma 1000001
using namespace std;

ull dp[ma][2];
ull sum[ma];

ull T, N;

void precomp() {
    dp[1][0] = 1; dp[1][1] = 1;
    sum[1] = 2;
    for (ull i=2; i<=ma; ++i) {
	dp[i][0] = dp[i-1][1];
	dp[i][1] = (dp[i-1][0]+dp[i-1][1])%mod;
	sum[i] = ((sum[i-1] + dp[i][0])%mod + dp[i][1])%mod;
    }
}

int main() {
    precomp();
    scanf("%llu", &T);
    while (T--) {
	scanf("%llu", &N);
	printf("%llu\n", sum[N]);
    }
    return 0;
}
