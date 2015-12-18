#include <iostream>
#include <vector>
#define tr(obj, it) for (typeof((obj).begin()) it  = (obj).begin(); it != (obj).end(); ++it)
using namespace std;

int ans[1010][1010];

int main() {
    int h, w, k, c, x, y;
    int ma = 0, id = 1;
    vector< vector< pair<int, int> > > p(100010);
    cin >> h >> w >> k;
    for (int i = 1; i <= k; ++i) {
	cin >> c;
	if (c > ma) { ma = c; id = i; }
	while (c--) {
	    cin >> x >> y;
	    p[i].push_back(make_pair(x, y));
	}
    }
    tr (p[id], it) {
        ans[(*it).first][(*it).second] = id;
    }
    for (int i = 1; i <= h; ++i) {
	for (int j = 1; j <= w; ++j) {
	    cout << ans[i][j] << " ";
	}
	cout << endl;
    }
    return 0;
}
