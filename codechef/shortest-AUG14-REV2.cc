#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

const int inf = 2147483647;

class Vertex {
    public:
	int vert;
	int cost;
	bool operator<(const Vertex& left) {
	    return cost > left.cost;
	}
	Vertex(int v, int d = inf):vert(v), cost(d) {}
};
#if 0
class lessThan {
    public:
	bool operator()(const Vertex& left, const Vertex& right) {
	    return left.cost < right.cost;
	}
};
#endif
int main() {
    int M, N, X, Y;
    map<int, vector<int> > direct, flip;
    map<int, Vertex> Graph;
    Graph.push_back(make_pair(1, Vertex(inf, inf)));
    Graph.push_back(make_pair(1, Vertex(1, 0)));

    cin >> N >> M;
    for (int i=0; i<M; i++) {
	cin >> X >> Y;
	if (X == Y) continue;
	direct[X].push_back(Y);
	flip[Y].push_back(X);
    }
    for (int i=2; i<N; i++) {
	Vertex v(i);
	Graph[i] = v;
    }
    for (map<int, Vertex>::iterator it = Graph.begin(); it != Graph.end(); ++it) {
	//Vertex v = *it;
	cout << "edge is.. " << it->second.vert << ", cost is.. " << it->second.cost << endl;
    }
    make_heap(Graph.begin(), Graph.end());
    for (map<int, Vertex>::iterator it = Graph.begin(); it != Graph.end(); ++it) {
	//Vertex v = *it;
	cout << "edge is.. " << it->second.vert << ", cost is.. " << it->second.cost << endl;
    }
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
