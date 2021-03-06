#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

const int inf = 2147483647;

#if 0
class Vertex {
    public:
	int vert;
	int cost;
	bool operator<(const Vertex& left) {
	    return cost > left.cost;
	}
	Vertex(int v, int d = inf):vert(v), cost(d) {}
};
#endif
class lessThan {
    public:
	bool operator()(const map<int, int>& left, const map<int, int>& right) {
	    return (left.second >= right.second);
	}
};

int main() {
    int M, N, X, Y;
    map<int, vector<int> > direct, flip;
    map<int, int> p;
    p.insert(make_pair(1, 0));

    cin >> N >> M;
    for (int i=0; i<M; i++) {
	cin >> X >> Y;
	if (X == Y) continue;
	direct[X].push_back(Y);
	flip[Y].push_back(X);
    }
    for (int i=2; i<N; i++) {
	p.insert(make_pair(i, inf));
    }
    for (map<int, int>::iterator it = p.begin(); it != p.end(); ++it) {
	//Vertex v = *it;
	cout << "edge is.. " << it->first << ", cost is.. " << it->second << endl;
    }
    make_heap(p.begin(), p.end(), lessThan());
    for (map<int, int>::iterator it = p.begin(); it != p.end(); ++it) {
	//Vertex v = *it;
	cout << "edge is.. " << it->first << ", cost is.. " << it->second << endl;
    }
    return 0;
}
#if 0
    while (!Graph.empty()) {
	Vertex g = Graph.front();
	int elem = g.vert;
	cout << "popping from heap.. " << elem << ", cost is.. " << Graph[elem].cost << endl;
	pop_heap(Graph.begin(), Graph.end());
	Graph.pop_back();
	vector<int> edges = direct[elem];
	for (vector<int>::iterator it = edges.begin(); it != edges.end(); ++it) {
	    if (Graph[elem].cost < Graph[*it].cost) {
		Graph[*it].cost = Graph[elem].cost;
		cout << "updating edge of.. " << Graph[*it].vert << ", cost is.. " << Graph[*it].cost << endl;
	    }
	}
	edges = flip[elem];
	for (vector<int>::iterator it = edges.begin(); it != edges.end(); ++it) {
	    if (Graph[elem].cost+1 < Graph[*it].cost) {
		Graph[*it].cost = Graph[elem].cost+1;
		cout << "Flip updating edge of.. " << Graph[*it].vert << ", cost is.. " << Graph[*it].cost << endl;
	    }
	}
    }
    cout << Graph[N].cost << endl;
    return 0;
}
#endif
#if 0
	pop_heap(Graph.begin(), Graph.end());
	Graph.pop_back();


    while (!q.empty()) {
	Vertex v = q.top();
	q.pop();
	vector edge = direct[v.vert];
	for (vector<int>::iterator it = edge.begin(); it != edge.end(); ++it) {
	    if (
#endif
