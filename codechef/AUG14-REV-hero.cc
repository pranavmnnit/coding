#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

const int inf = 2147483647;

int main() {
    int N, M;
    int X, Y;
    int cost[100015]; // from 1 to vertex v
    int arr[100010][2];
    bool change = true;
    map<int, vector<int> >::iterator it;
    vector<int>::iterator vitr;
    fill_n(cost, 100005, inf);

    cin >> N >> M;
    for (int i = 0; i<M; i++) {
	cin >> X >> Y;
	if (X == Y) continue;
	arr[i][0] = X; arr[i][1] = Y;
    }
    cost[1] = 0;
    while (change) {
	//cout << "changing" << endl;
	change = false;
	for (int i = 0; i<M; i++) {
	    if (cost[arr[i][0]] == inf && cost[arr[i][1]] == inf) continue;
	    if (cost[arr[i][0]] < cost[arr[i][1]]) {
		//cout << "updating cost of " << arr[i][1] << " to " << cost[arr[i][0]] << endl;
		cost[arr[i][1]] = cost[arr[i][0]];
		change = true;
	    }
	    if (cost[arr[i][1]]+1 < cost[arr[i][0]]) {
		//cout << "updating cost of " << arr[i][0] << " to " << cost[arr[i][1]]+1 << endl;
		cost[arr[i][0]] = cost[arr[i][1]]+1;
		change = true;
	    }
	}
    }
    cout << ((cost[N] == inf) ? -1 : cost[N])  << endl;
    return 0;
}
