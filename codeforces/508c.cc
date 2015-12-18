#include <iostream>
using namespace std;

int g[301];
int sum[301];

int main() {
    int m, t, r, i, j, k;
    int ans=0;
    cin >> m >> t >> r;
    if (t<r) { cout << -1 << endl; return 0; }
    for (i=1; i<=m; ++i) {
	cin >> g[i];
    }
    for (i=1; i<=m; ++i) {
	ans+=(r-sum[g[i]]);
	for (j=g[i]+sum[g[i]]-r+1; j<=g[i]; ++j) {
	    for (k=j; k<j+t; ++k) {
		if (k<1) {
		    continue;
		}
		sum[k]+=1;
	    }
	}
    }
    cout << ans << endl;
    return 0;
}
