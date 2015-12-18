#include <iostream>
#include <map>
#define ll long long
#define Map map<ll, A>
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

using namespace std;

typedef struct A {
    ll type;
    ll clan_req;
    ll clan_add;
    ll sub;
    public:
    A(ll t, ll a, ll b, ll c) : type(t), clan_req(a), clan_add(b), sub(c) { }
} A;

bool ispos(ll num, Map& M) {
    ll cnt = num;
    tr(M, it) {
	if ((*it).second.type == 0) {
	    if ((*it).second.sub < cnt) {
		cnt -= (*it).second.sub;
	    } else {
		return false;
	    }
	} else {
	    if ((*it).second.clan_req <= cnt) {
		cnt += (*it).second.clan_add;
	    }
	}
    }
    return true;
}

int main() {
    ll t, x, y, p, q, r, c, d;
    cin >> t;
    while (t--) {
	cin >> d;
	cin >> c;
	Map M;
	ll ma = 0;
	for (ll i = 0 ; i < c; ++i) {
	    cin >> x >> y;
	    M.insert(make_pair(x, A(0, 0, 0, y)));
	    ma += y;
	}
	cin >> c;
	for (ll i = 0; i < c; ++i) {
	    cin >> p >> q >> r;
	    M.insert(make_pair(p, A(1, q, r, 0)));
	}
	//binary seach
	ll lo = 0;
	ll hi = 2 * (ma + 1);
	ll mid, ans = 0;
	while (lo <= hi) {
	    mid = lo + ((hi - lo)/(1LL * 2));
	    if (ispos(mid, M)) {
		ans = mid;
		hi = mid - 1;
	    } else {
		lo = mid + 1;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
