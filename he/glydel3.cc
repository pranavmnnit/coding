#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int inf = 1e6;

int main() {
    int t;
    int a,b; int u,v; long D;
    int graph[1010][1010];
    int dist[1010];
    cin >> t;
    while(t--) {
	D = 0;
	cin >> a >> b;
	memset(graph, 0, sizeof(graph[0][0])*1010*1010);
	memset(dist, 0, sizeof(dist[0])*1010);
	//for (int i=0; i<1011; ++i) {
	//    dist[i] = inf;
	//}
	while (b--) {
	    cin >> u >> v;
	    graph[u][v] = 1;
	}
	for (int i=0;i<a;++i) {
	    for (int j=0; j<a; ++j) {
		for (int k=0; k<a; ++k) {
		    if (dist[i][k] + dist[k][j] < dist[i][j]) {
			dist[i][j] = dist[i][k] + dist[k][j];
		    }
		}
	    }
	}
	for (int i=0;i<a;++i) {
	    D += dist[i];
	}
    }
    return 0;
}

