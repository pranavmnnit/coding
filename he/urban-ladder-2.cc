#include <iostream>
#include <map>
#define min(a, b) ((a)<(b)?(a):(b))
using namespace std;

int main() {
    int n, m, q, cost;
    cin >> n >> m;
    string s, d;
    map<string, int> M;
    for (int i = 0; i < n; ++i) {
	cin >> s;
	M.insert(make_pair(s, i));
    }
    int dist[101][101] = {0};
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j) {
	    if (i != j ) dist[i][j] = dist[j][i] = 1e6;
	}
    }
    while (m--) {
	cin >> s >> d >> cost;
	dist[M[s]][M[d]] = dist[M[d]][M[s]] = cost;
    }
    for (int k = 0; k < n; ++k) {
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j < n; ++j) {
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	    }
	}
    }
    cin >> q;
    while (q--) {
	cin >> s >> d;
	cout << dist[M[s]][M[d]] << endl;
    }
    return 0;
}
