#include <iostream>
#include <vector>
#define ll long long
#define pb push_back
#define tr(obj, it) for(typeof((obj).begin()) it = (obj).begin(); it != (obj).end(); ++it)
using namespace std;

int main() {
    vector< vector<int> > v(30);
    ll sum[30];
    ll ans = 0;
    ll prefix[100010];
    string str;
    for (ll i = 0; i < 26; ++i) {
	cin >> sum[i];
    }
    cin >> str;
    ll sz = static_cast<ll>(str.size());
    prefix[0] = sum[str[0] - 'a'];
    v[str[0] - 'a'].pb(0);

    for (int i = 1; i < sz; ++i) {
	tr (v[str[i] - 'a'], it) {
	    if ((prefix[i-1] - prefix[*it]) == 0) ++ans;
	}
	prefix[i] = prefix[i-1] + sum[str[i] - 'a'];
	v[str[i] - 'a'].pb(i);
    }
    cout << ans << endl;
}
