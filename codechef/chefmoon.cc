#include <iostream>
#define min(a, b) ((a)<(b)?(a):(b))
#define INF 9999999
using namespace std;

int dist[101][101];

void pre(int n) {
    int i, j, k;
    for (k=0; k<n; ++k) {
	for (i=0; i<n; ++i) {
	    for (j=0; j<n; ++j) {
		dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
	    }
	}
    }
}

int main() {
    int n, m, k, a, b, d, q;
    cin >> n >> m >> k;
    for (int i=0; i<n; ++i) {
	for (int j=0; j<n; ++j) {
	    if (i==j) dist[i][j]=0;
	    else dist[i][j]=INF;
	}
    }
    for (int i=0; i<m; ++i) {
	cin >> a >> b >> d;
	--a; --b;
	dist[a][b]=dist[b][a]=d;
    }
    pre(n);
    cin >> q;
    while (q--) {
	cin >> a >> b;
	--a; --b;
	if (dist[a][b]<=k) {
	    cout << "YES" << endl;
	} else {
	    cout << "NO" << endl;
	}
    }
    return 0;
}
