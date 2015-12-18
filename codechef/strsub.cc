#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long
#define C(n) (((n) * ((n)+1)) / 2)

using namespace std;

int main() {
    ll t, n, k, Q, l, r;
    char str[100010];
    scanf("%lld", &t);
    while (t--) {
	scanf("%lld %lld %lld", &n, &k, &Q);
	scanf("%s", str);
	ll* idx = new ll[n + 1];
	ll* cum = new ll[n + 1];
	queue<ll> q;
	ll cnt[2] = {0};
	int i = 1;
	q.push(0); idx[0] = 0; cum[0] = 1; // K is atleast 1
	++cnt[str[0] - '0'];
	while (i < n) {
	    q.push(i);
	    ++cnt[str[i] - '0'];
	    while (cnt[0] > k || cnt[1] > k) {
		--cnt[str[q.front()] - '0'];
		q.pop();
	    }
	    idx[i] = q.front();
	    cum[i] = cum[i-1] + (i - idx[i] + 1);
	    ++i;
	}

	while (Q--) {
	    scanf("%lld %lld", &l, &r);
	    --l; --r;
	    ll del = lower_bound(idx + l, idx + r + 1, l) - idx;
	    printf("%lld\n", C(del - l) + cum[r] - ((del > 0) ? cum[del - 1] : 0));
	}
	delete[] idx;
	delete[] cum;
    }
    return 0;
}
