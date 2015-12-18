#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main() {
    ll n, m, a, b, c;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= m; ++i) {
	scanf("%lld %lld %lld", &a, &b, &c);
    }
    for (ll i = 1; i <= n/2; ++i) {
	printf("%lld ", i);
    }
    printf("\n");
    return 0;
}
