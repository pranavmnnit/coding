#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define ll unsigned long long
#define PL pair<ll, ll>
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a, b) make_pair((a), (b))

using namespace std;

const ll MOD = 1e9+7;

ll g[120][120];

void init(ll n, ll m) {
    g[0][0] = 1;
    for (ll i = 0; i < m; ++i) {
	g[1][i] = 1;
    }
    for (ll i = 2; i <= n; ++i) {
	for (ll j = 0; j < m; ++j) {
	    g[i][j] = (g[i-1][j] * m) % MOD;
	}
    }
    g[n+1][0] = (g[n][0] * m) % MOD;
}

void update(ll n1, ll m1, ll n2, ll m2, ll n, ll m) {
    g[n2][m2] = (g[n2][m2] + g[n1][m1]) % MOD;
    for (ll i = n2 + 1; i <= n; ++i) {
	ll ans = 0;
	for (ll k = 0; k < m; ++k) {
	    g[i][k] = 0;
	    ans = (ans + g[i-1][k]) % MOD;
	}
	for (ll k = 0; k < m; ++k) g[i][k] = ans;
    }
    if (n2 < n+1) {
	g[n+1][0] = 0;
	for (ll i = 0; i < m; ++i) {
	    g[n+1][0] = (g[n][i] + g[n+1][0]) % MOD;
	}
    }
}

int main() {
    ll n, m, k;
    ll n1, m1, n2, m2;
    multiset< pair< PL, PL > > s;
    cin >> n >> m >> k;
    init(n, m);

    for (ll i = 0; i < k; ++i) {
	cin  >> n1 >> m1 >> n2 >> m2;
	s.insert(mp(mp(n2, m2), mp(n1, m1)));
    }
    tr (s, it) {
	n1 = (*it).second.first, m1 = (*it).second.second, n2 = (*it).first.first, m2 = (*it).first.second;
	update(n1, m1, n2, m2, n, m);
    }
    cout << g[n+1][0] << endl;
    return 0;
}
