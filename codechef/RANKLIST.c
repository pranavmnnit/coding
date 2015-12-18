#include <stdio.h>
#define ll long long

int main() {
    ll t, n, s, i, cur;
    scanf("%lld", &t);
    while (t--) {
	scanf("%lld %lld", &n, &s);
	i = 1;
	cur = n;
	while (s >= cur) cur += (i++);
	printf("%lld\n", n-i+1);
    }
    return 0;
}
