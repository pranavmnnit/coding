#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll cnt, a, ma = -1;
    ll ans = 0;
    ll arr[1000010] = {0};
    cin >> cnt;
    for (ll i = 0; i < cnt; ++i) {
	cin >> a;
	arr[a]++;
	if (a > ma) ma = a;
    }
    ans += ((arr[ma]/4) * ma * ma);
    arr[ma] = (arr[ma] / 4);
    for (ll i = ma-1; i > 0; --i) {
	if (arr[i+1] == 0) {
	    ans += ((arr[i]/4) * i * i);
	} else if (arr[i+1] == 1) {
	    ++arr[i];
	    ans += ((arr[i]/4) * i * i);
	} else if (arr[i+1] == 2) {
	    if (arr[i] >= 2) {
		ans += (i * (i + 1));
		arr[i] -= 2;
	    }
	    ans += ((arr[i]/4) * i * i);
	} else if (arr[i+1] == 3) {
	    if (arr[i] >= 1) {
		ans += (i * (i + 1));
		arr[i]--;
	    }
	    ans += ((arr[i]/4) * i * i);
	}
	arr[i] = (arr[i] / 4);
    }
    cout << ans << endl;
    return 0;
}
