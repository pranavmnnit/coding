#include <iostream>
#define ll long long

using namespace std;

const long long MOD  = 1e9+7;

ll way[310][1810][10];

void pre() {
    for (ll i = 0; i <= 9; ++i) way[0][0][i] = 1;

    for (ll i = 1; i <= 300; ++i) {
	for (ll j = 0; j <= 6*i; ++j) {
	    for (ll k = 0; k <= 9; ++k) {
		way[i][j][k] = ((k > 0)? way[i-1][j][k-1] : 0);
		way[i][j][k] = (way[i][j][k] + ((j >= 4) ? way[i-1][j-4][k] : 0))%MOD;
		way[i][j][k] = (way[i][j][k] + ((j >= 6) ? way[i-1][j-6][k] : 0))%MOD;
		way[i][j][k] = (way[i][j][k] + way[i-1][j][k])%MOD;
	    }
	}
    }
}

int main() {
    ll t, r, b, w;
    pre();
    cin >> t;
    while (t--) {
	cin >> r >> b >> w;
	if (r > 1800) {
	    cout << 0 << endl;
	    continue;
	}
	cout << way[b][r][w] << endl;
    }
    return 0;
}
