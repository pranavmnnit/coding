#include <stdio.h>
#define ll unsigned long long

int main() {
    ll cnt[101];
    ll t, s, c, k, i, j;
    scanf("%llu", &t);
    while (t--) {
	scanf("%llu %llu %llu", &s, &c, &k);
	for (i = 0; i < 101; ++i) cnt[i] = 0;
	if (s) cnt[s] = 3;
	if (s > 1) for (i = s-1, j = 1; i >= 1; --i, ++j) cnt[i] = (1LL << j);

	for (i = 1, j = s; (i <= c) && (j > 1); ++i, --j) {
	    cnt[j] += cnt[j-1];
	    cnt[j-1] = 0;
	}
	for (; i <= c; ++i) cnt[1] += (1LL << i);

	for (i = 49; i >= 1; --i) cnt[i] += cnt[i+1];

	printf("%llu\n", cnt[k]);
    }
    return 0;
}
