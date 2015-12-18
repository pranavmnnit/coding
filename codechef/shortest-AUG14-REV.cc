#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

using namespace std;

const int inf = 2147483647;

int main() {
    int M, N, X, Y;
    map< int, vector<int> > direct, flip;
    set< pair<int, int> >p;
    int cost[100006];

    fill_n(cost, 100006, inf);
    p.insert(make_pair(0, 1));
    cin >> N >> M;
    for (int i=0; i<M; i++) {
	cin >> X >> Y;
	if (X == Y) continue;
	direct[X].push_back(Y);
	flip[Y].push_back(X);
    }
    while (!p.empty()) {
	pair<int, int> best = *(p.begin());
	p.erase(p.begin());
	tr(direct[best.second], it) {
	    if (best.first < cost[*it]) {
		if (cost[*it] != inf) {
		    p.erase(make_pair(cost[*it], *it));
		}
		cost[*it] = best.first;
		p.insert(make_pair(cost[*it], *it));
	    }
	}

	tr(flip[best.second], it) {
	    if (best.first+1 < cost[*it]) {
		if (cost[*it] != inf) {
		    p.erase(make_pair(cost[*it], *it));
		}
		cost[*it] = best.first+1;
		p.insert(make_pair(cost[*it], *it));
	    }
	}
    }
    cout << ((cost[N] == inf) ? -1 : cost[N]) << endl;
    return 0;
}
