#include <iostream>
#include <cmath>
#include <cstdio>
#define ull unsigned long long
using namespace std;

int main() {
    ull t, n;
    scanf("%llu", &t);
    while (t--) {
	scanf("%llu", &n);
	if (n == 1) {
	    printf("1\n");
	    continue;
	}
	ull sq = (ull)sqrt(1.0*n);
	ull ans = 1+n;
	for (ull i = 2; i <= sq; ++i) {
	    if (n%i == 0) ans = ans + i + ((n/i != i) ? (n/i) : 0);
	}
	printf("%llu\n", ans);
    }
    return 0;
}
