#include <stdio.h>
#define ll long long

int main() {
    ll cnt[101];
    ll t, s, c, k, i, j;
    scanf("%lld", &t);
    while (t--) {
	scanf("%lld %lld %lld", &s, &c, &k);
	for (i = 0; i < 101; ++i) cnt[i] = 0;
	if (s) cnt[s] = 3;
	for (i = s-1, j = 1; i >= 1; --i, ++j) cnt[i] = (1LL << j);

	for (i = 1, j = s; (i <= c) && (j > 1); ++i, --j) {
	    cnt[j] += cnt[j-1];
	    cnt[j-1] = 0;
	}
	for (; i <= c; ++i) cnt[1] += (1 << i);

	for (i = 49; i >= 1; --i) cnt[i] += cnt[i+1];

	printf("%lld\n", cnt[k]);
    }
    return 0;
}
