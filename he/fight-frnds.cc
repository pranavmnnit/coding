#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, a, b;
    queue<int> q;
    int graph[1011][1011] = {0};
    bool visited[1011] = {false};
    cin >> n >> m >> a >> b;
    int f1, f2; bool found = false;

    for (int i=0; i<1011; ++i) {
	for (int j=0; j<1011; ++j) {
	    graph[i][j] = 1;
	}
    }
    for (int i=0; i<m; ++i) {
	cin >> f1 >> f2;
	graph[f1][f2] = graph[f2][f1] = 0;
    }
    vector<int> dist(n, -1);
    dist[a] = 0;
    q.push(a); visited[a] = true;
    while (!q.empty()) {
	int f = q.front(); q.pop();
	if (f == b) {
	    found = true;
	}
	if (!found) {
	    for (int i=0; i<n; ++i) {
		if (graph[f][i+1] && !visited[i+1]) {
		    visited[i+1] = true;
		    dist[i+1] = dist[f] + 1;
		    q.push(i+1);
		}
	    }
	} else {
	   break;
	}
    }
    cout << dist[b] << endl;
    return 0;
}

