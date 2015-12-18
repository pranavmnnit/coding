#include <iostream>
using namespace std;

int main() {
    int n, m, hb, hg, X;
    int b[101], g[101];
    for (int i = 0; i <= 100; ++i) { b[i] = g[i] = 0; }
    cin >> n >> m;
    cin >> hb;
    for (int i = 0; i < hb; ++i) {
	cin >> X;
	b[X] = 1;
    }
    cin >> hg;
    for (int i = 0; i < hg; ++i) {
	cin >> X;
	g[X] = 1;
    }
    for (int i = 0, j = 0, cnt = 0; cnt < 100*n*m; ++cnt, i = (i + 1)%n, j = (j + 1)%m) {
	if (b[i] || g[j]) b[i] = g[j] = 1;
    }
    for (int i = 0; i < n; ++i) {
	if (!b[i]) {
	    cout << "No" << endl;
	    return 0;
	}
    }
    for (int i = 0; i < m; ++i) {
	if (!g[i]) {
	    cout << "No" << endl;
	    return 0;
	}
    }
    cout << "Yes" << endl;
    return 0;
}
