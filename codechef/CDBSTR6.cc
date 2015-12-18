#include <iostream>
#include <cmath>
#include<vector>
#define ll long long
using namespace std;

int Do(int bit, vector<ll>& vec) {
    cout << "called with bit= " << bit << endl;
    if (vec.size() < 2) {
	//cout << "size<2, returing..\n";
	return 0;
    }
    ll s = 0, e = 1;
    ll n = vec.size();
    int bit2 = bit;
    while (bit2>=0 && !(vec[s]&(1<<bit2))) --bit2;
    if (!bit2) return 0;
    bit = bit2;
    while (e<n && (vec[e]&(1<<bit))) ++e;
    cout << "now bit= " << bit << "s= " << s << ", e= " << e << endl;
    if (e-1 == s) return 0;
    cout << "returning e= " << e << endl;
    return e;
}

void print(vector<ll>& vec) {
    cout << "\n==================================\n";
    int sz = vec.size();
    for (int i=0; i<sz; ++i) {
	cout << vec[i] << " ";
    }
    cout << "\n==================================\n";
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
	cout << "will take next..\n";
	cin >> n;
	vector<ll> a(n);
	for (int i=0; i<n; ++i) {
	    cin >> a[i];
	}
	sort(a.begin(), a.end(), std::greater<ll>());
	print(a);
	int bit = log2(a[0]);
	ll ans = 0;
	ll e = 0;
	while ((bit >= 0) && (a.size() > 1)) {
	    if ((e = Do(bit, a))) {
		if (e < static_cast<ll>(a.size())) a.erase(a.begin()+e, a.end());
		else {
		    cout << "end for bit= " << bit << endl;
		    for (vector<ll>::iterator it = a.begin(); it != a.end(); ++it) {
			*it = (*it) ^ (1<<bit);
		    }
		    ans+=(1<<bit);
		}
	    } else {
		a.erase(a.begin());
	    }
	    --bit;
	    cout << "ans= " << ans << endl;
	    print(a);
	}
	cout << "Final= " << ans << endl;
    }
    return 0;
}
