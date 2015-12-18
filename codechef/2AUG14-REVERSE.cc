#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M;
    int X, Y;
    bool visited[100005] = {false};
    int cost[100005];
    int levelcost = 0;
    map<int, vector<int> > direct, flip;
    map<int, vector<int> >::iterator it;
    vector<int>::iterator vitr;
    queue<int> bfs; //vertex
    queue<int> forflip;
    fill_n(cost, 100005, 2147483647);

    cin >> N >> M;
    while (M--) {
	cin >> X >> Y;
	if (X == Y) continue;
	direct[X].push_back(Y);
	flip[Y].push_back(X);
    }
    bfs.push(1);
    forflip.push(1);
    cost[1] = 0;
    visited[1] = true;
    while (!bfs.empty() || !forflip.empty()) {
	queue<int> temp = bfs;
	forflip = bfs;
	while (!bfs.empty()) {
	    int elem = bfs.front();
	    //cout << "Popping element: " << elem << ", cost is: " << cost[elem] << endl;
	    bfs.pop();
	    vector<int> vec = direct[elem];
	    for (vitr = vec.begin(); vitr != vec.end(); ++vitr) {
		if (!visited[*vitr]) {
		    cost[*vitr] = levelcost;
		    if (*vitr == N) break;
		    bfs.push(*vitr);
		    forflip.push(*vitr);
		    visited[*vitr] = true;
		    //cout << "Pushing element: " << *vitr << ", cost is: " << cost[*vitr] << endl;
		}
	    }
	}
	++levelcost;
	if (forflip.empty()) {
	    //cout << "filling forflip with bfs" << endl;
	    //cout << temp.front() << endl;
	    forflip = temp;
	}
	while (!forflip.empty()) {
	    int elem = forflip.front();
	    forflip.pop();
	    vector<int> vec = flip[elem];
	    for (vitr = vec.begin(); vitr != vec.end(); ++vitr) {
		if (cost[*vitr] > levelcost) {
		    cost[*vitr] = levelcost;
		    visited[*vitr] = true;
		    if (*vitr == N) break;
		    bfs.push(*vitr);
		    //cout << "Flip Pushing element: " << *vitr << ", cost is: " << cost[*vitr] << endl;
		}
	    }
	}
    }
    cout << ((cost[N] == 2147483647) ? -1 : cost[N])  << endl;
    return 0;
}
#if 0
    //bfs
    bfs.push(1);
    cost[1] = 0;
    while (!bfs.empty()) {
	int elem = bfs.top();
	cout << "Popping element: " << elem << ", cost is: " << cost[elem] << endl;
	visited[elem] = true;
	cout << "Visited: " << elem << endl;
	bfs.pop();
	vector<int> vec;
	//direct
	vec = direct[elem];
	for (vitr = vec.begin(); vitr != vec.end(); ++vitr) {
	    if ((visited[*vitr] && cost[elem] < cost[*vitr]) || (!visited[*vitr])) {
	    //if (visited && cost less) or (!visited)
	    //if (!visited[*vitr] && cost[elem] < cost[*vitr])
		bfs.push(*vitr);
		cost[*vitr] = cost[elem];
		cout << "Pushing element: " << *vitr << ", cost is: " << cost[*vitr] << endl;
	    }
	}
	//flip
	vec = flip[elem];
	for (vitr = vec.begin(); vitr != vec.end(); ++vitr) {
	    if ((visited[*vitr] && cost[elem]+1 < cost[*vitr]) || (!visited[*vitr])) {
	    //if (!visited[*vitr] && cost[*vitr] > cost[elem]+1)
		bfs.push(*vitr);
		cost[*vitr] = cost[elem] + 1;
		cout << "Flip Pushing element: " << *vitr << ", cost is: " << cost[*vitr] << endl;
	    }
	}
    }
    cout << ((cost[N] == 2147483647) ? -1 : cost[N])  << endl;
    return 0;
}
#endif
#if 0
    vector<int> vec;
    for (it = direct.begin(); it != direct.end(); ++it)  {
	vec = it->second;
	cout << it->first << "=> ";
	for (vector<int>:: iterator vitr = vec.begin(); vitr != vec.end(); ++vitr) {
	    cout << *vitr << ", ";
	}
	cout << endl;
    }
    for (it = flip.begin(); it != flip.end(); ++it)  {
	vec = it->second;
	cout << it->first << "=> ";
	for (vector<int>:: iterator vitr = vec.begin(); vitr != vec.end(); ++vitr) {
	    cout << *vitr << ", ";
	}
	cout << endl;
    }
    return 0;
}
#endif
