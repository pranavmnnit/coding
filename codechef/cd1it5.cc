#include <iostream>
#include <vector>
#include <queue>
#define tr(obj, it) for (typeof (obj.begin()) it = obj.begin(); it!= obj.end(); ++it)

using namespace std;

vector< vector<int> > dir(100010);

string isPossible(int n1, int n2) {
    bool visited[100010]={0};
    queue<int> q;
    q.push(n1);
    while(!q.empty()) {
	int n=q.front(); q.pop();
	if (!visited[n]) {
	    visited[n]=true;
	    tr (dir[n], it) {
		if (*it==n2) return "Yes";
		q.push(*it);
	    }
	}
    }
    return "No";
}

int main() {
    int n, q, type, n1, n2;
    scanf("%d %d", &n, &q);
    while (q--) {
	scanf("%d %d %d", &type, &n1, &n2);
	if (type == 1) {
	    printf("%s\n", isPossible(n1, n2).c_str());
	} else {
	    dir[n1].push_back(n2);
	    dir[n2].push_back(n1);
	}
    }
    return 0;
}
