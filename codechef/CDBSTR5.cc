#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int to[10001][10001], cnt[10001];
bool visited[10001];

int main() {
    int t, n, a, b;
    cin >> t;
    while (t--) {
	cin >> n;
	memset(to, 0, sizeof(to));
	memset(cnt, 0, sizeof(cnt));
	memset(visited, 0, sizeof(visited));
	for (int i=0; i<n-1; ++i) {
	    cin >> a >> b;
	    to[a][cnt[a]++]=b;
	    to[b][cnt[b]++]=a;
	}
	bool flag=0;
	cout << "done readin.\n";
	queue<int> q;
	q.push(1);
	int l = 0, last = 0; visited[1] = true;
	while (!q.empty()) {
	    int c = q.front(); q.pop();
	    cout << "c= " << c << "cnt= " << cnt[c] << endl;
	    if (c == 0) { ++l; continue; }
	    flag=0;
	    for (int i=0; i<cnt[c]; ++i) {
		if (!visited[to[c][i]]) {
		    cout << "pusin= " << to[c][i] << endl;
		    flag=1;
		    q.push(to[c][i]);
		    visited[to[c][i]] = true;
		}
		last = to[c][i];
	    }
	    if (cnt[c] && flag) q.push(0);
	}
	cout << "l= " << l << ", last= " << last << endl;
	memset(visited, 0, sizeof(visited));
	queue<int> temp; swap(temp, q);
	q.push(last); visited[last] = true;
	l = 0;
	while (!q.empty()) {
	    int c = q.front(); q.pop();
	    cout << "from " << c << endl;
	    if (c == 0) { ++l; continue; }
	    flag=0;
	    for (int i=0; i<cnt[c]; ++i) {
		if (!visited[to[c][i]]) {
		    cout << "pusin= " << to[c][i] << endl;
		    flag=1;
		    q.push(to[c][i]);
		    visited[to[c][i]] = true;
		}
	    }
	    if (cnt[c] && flag) q.push(0);
	}
	cout << l << endl;
    }
    return 0;
}
