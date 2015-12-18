#include <iostream>
#define min(a, b) ((a)<(b)?(a):(b))
using namespace std;

int d[101][101];

int main() {
    int t, n , a, b, x, y;
    cin >> t;
    while (t--) {
	cin >> n >> a >> b;
	for (int i = 0 ; i <= 100; ++i) {
	    for (int j = 0; j <= 100; ++j) {
		d[i][j] = 100005;
		if (i == j) d[i][j] = 0;
	    }
	}
	for (int i = 1; i < n; ++i) {
	    cin >> x >> y;
	    d[x][y] = d[y][x] = 1;
	}
	for (int i = 1; i <= n; ++i) {
	    for (int j = 1; j <= n; ++j) {
		for (int k = 1; k <= n; ++k) {
		    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
		}
	    }
	}
	cout << d[a][b] << endl;
    }
    return 0;
}
