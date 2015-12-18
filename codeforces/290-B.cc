#include <iostream>
#include <queue>
#include <stack>
#include <set>
using namespace std;

string a[51];

int dfs(int i, int j, int n, int m, char ch) {
    stack< pair<int, int> > s;
    s.push(make_pair(i, j));
    bool visited[51][51]={0};
    bool se[51][51]={0};
    while (!s.empty()) {
	pair<int, int> p = s.top(); s.pop();
	if (!visited[p.first][p.second]) {
	    visited[p.first][p.second]=1;
	    if (p.first-1>=0 && a[p.first-1][p.second]==ch && !visited[p.first-1][p.second]) {
		if (se[p.first-1][p.second]==1) return 1;
		s.push(make_pair(p.first-1, p.second));
		se[p.first-1][p.second]=1;
	    }
	    if (p.second+1<m && a[p.first][p.second+1]==ch && !visited[p.first][p.second+1]) {
		if (se[p.first][p.second+1]==1) return 1;
		se[p.first][p.second+1]=1;
		s.push(make_pair(p.first, p.second+1));
	    }
	    if (p.first+1<n && a[p.first+1][p.second]==ch && !visited[p.first+1][p.second]) {
		if (se[p.first+1][p.second]==1) return 1;
		se[p.first+1][p.second]=1;
		s.push(make_pair(p.first+1, p.second));
	    }
	    if (p.second-1>=0 && a[p.first][p.second-1]==ch && !visited[p.first][p.second-1]) {
		if (se[p.first][p.second-1]==1) return 1;
		se[p.first][p.second-1]=1;
		s.push(make_pair(p.first, p.second-1));
	    }
	}
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
	    cin >> a[i];
    }
    for (int i=0; i<n; ++i) {
	for (int j=0; j<m; ++j) {
	    if (dfs(i,j, n, m, a[i][j])) {
		cout << "Yes" << endl; return 0;
	    }
	}
    }
    cout << "No" << endl;
    return 0;
}
