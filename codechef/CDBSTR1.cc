#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

bool ispossible (ll cnt, ll dist, vector<ll>& vec) {
    vector<ll>::iterator it = vec.begin();
    ll d = 0, c = 1;
    ++it;
    for (;it != vec.end(); ++it) {
	d += (*it - *(it-1));
	if (d < dist) continue;
	else {
	    d = 0;
	    ++c;
	    if (c == cnt) return 1;
	}
    }
    return 0;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
	cin >> n >> k;
	vector<ll> vec(n);
	for (ll i=0; i<n; ++i) {
	    cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	ll b = 0, e = 2*(vec.back() - *vec.begin());
	ll mid = 0, ans = -1;
	while (b<=e) {
	    mid = b+(e-b)/2;
	    if (ispossible(k, mid, vec)) {
		if (mid>ans) ans=mid;
		b = mid+1;
	    } else {
		e = mid-1;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
