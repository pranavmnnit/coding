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
 
map< pair<ll, ll>, ll > edge;
ll layer[100010];
 
ll mypow(ll num, ll po) {
    ll res = 1;
    while (po) {
        if (po%2) {
            res *= num;
            res %= MOD;
            --po;
        } else {
            num *= num;
            num %= MOD;
            po /= 2;
        }
    }
    return res;
}
void update(ll n1, ll m1, ll n2, ll m2, ll n, ll m, ll nl, ll ml) {
    ll sum = 0;
    if (n2 == nl) {
        layer[m2] += (edge.find(mp(n1, m1)) != edge.end())?(edge.find(mp(n1, m1))->second):mypow(m, n1 - 1);
    } else {
        for (ll i = 0; i < m; ++i) {
            sum += layer[i];
        }
 
        if (n2 != n + 1) {
            for (ll i = 0; i < m; ++i) {
                layer[i] = mypow(m, (n2 - nl - 1))*sum;
            }
        } else {
            layer[0] = mypow(m, (n2 - nl - 1))*sum;
        }
 
        if (n1) {
            layer[m2] += (edge.find(mp(n1, m1)) != edge.end())?(edge.find(mp(n1, m1))->second):mypow(m, n1 - 1);
        } else {
            layer[m2] += 1;
        }
    }
 
    edge.insert(mp(mp(n2, m2), layer[m2]));
}
int main() {
    ll n, m, k;
    ll n1, m1, n2, m2, nl, ml;
    multiset< pair< PL, PL > > s;
    cin >> n >> m >> k;
 
    layer[0] = 1;
 
    for (ll i = 0; i < k; ++i) {
        cin >> n1 >> m1 >> n2 >> m2;
        s.insert(mp(mp(n2, m2), mp(n1, m1)));
    }
    nl = ml = 0;
    tr (s, it) {
        n1 = (*it).second.first, m1 = (*it).second.second, n2 = (*it).first.first, m2 = (*it).first.second;
        //cout << "going from " << n1 << " " << m1 << " to " << n2 << " " << m2 << endl;
        update(n1, m1, n2, m2, n, m, nl, ml);
        nl = n2; ml = m2;
        //cout << "now..\n";
        //print(m);
    }
    if (nl == n + 1) {
        cout << layer[0] << endl;
    } else {
        ll sum = 0;
        for (ll i = 0; i < m; ++i) {
            sum += layer[i];
        }
        //cout << "layer sum= " << sum << endl;
        if (nl != n) {
            for (ll i = 0; i < m; ++i) {
                layer[i] = mypow(m, (n - nl - 1))*sum;
            }
            //cout << "each layer= " << layer[0] << endl;
            sum = 0;
            for (ll i = 0; i < m; ++i) {
                sum += layer[i];
            }
            //cout << "no sum= " << sum << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
