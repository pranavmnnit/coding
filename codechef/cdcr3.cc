#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    char arr[101][101]={0};
    map< int, pair<int, int> > s;
    int d[101][101];
    for (int i=0; i<101; ++i) {
	for (int j=0; j<100; ++j) {
	    d[i][j]=10000;
	}
    }
    int dir[101][101];
    bool visited[101][101]={false};
    int r, c, h_x, h_y, l_x, l_y;
    cin >> r >> c;
    for (int i=0; i<r; ++i) {
	for (int j=0; j<c; ++j) {
	    cin >> arr[i][j];
	    if (arr[i][j]=='H') { h_x=i; h_y=j; }
	    if (arr[i][j]=='L') { l_x=i; l_y=j; }
	}
    }
    s.insert(make_pair(0, make_pair(h_x, h_y))); d[h_x][h_y]=0; dir[h_x][h_y]=0;
    while (!s.empty()) {
	pair<int, int> p = s.begin()->second; s.erase(s.begin());
	cout << "x=" << p.first << ", y=" << p.second << ", d=" << d[p.first][p.second] << ", dir=" << dir[p.first][p.second] << endl;
	if (p.first==l_x && p.second==l_y) continue;
	if (p.first-1>=0 && arr[p.first-1][p.second]!='*')
	    if (!dir[p.first][p.second] || dir[p.first][p.second] == 1) {
		if (d[p.first][p.second] < d[p.first-1][p.second]) {
		    s.erase(make_pair(d[p.first][p.second], make_pair(p.first-1, p.second)));
		    d[p.first][p.second]=d[p.first-1][p.second];
		    s.erase(make_pair(d[p.first][p.second], make_pair(p.first-1, p.second)));
	       	|| d[p.first-1][p.second]>d[p.first][p.second]+1) {
		s.insert(make_pair(d[p.first][p.second], make_pair(p.first-1, p.second)));
		dir[p.first-1][p.second]=1;
		d[

	if (p.second+1<c && arr[p.first][p.second+1]!='*')
	    if (!dir[p.first][p.second] || dir[p.first][p.second] == 2 || d[p.first][p.second+1]>d[p.first][p.second]+1)
		s.insert(make_pair(p.first, p.second+1)); dir[p.first][p.second+1]=2;

	if (p.first+1<r && arr[p.first+1][p.second]!='*')
	    if (!dir[p.first][p.second] || dir[p.first][p.second] == 3 || d[p.first+1][p.second]>d[p.first][p.second]+1)
		s.insert(make_pair(p.first+1, p.second)); dir[p.first+1][p.second]=3;

	if (p.second-1>=0 && arr[p.first-1][p.second]!='*')
	    if (!dir[p.first][p.second] || dir[p.first][p.second] == 4 || d[p.first-1][p.second]>d[p.first][p.second]+1)
		s.insert(make_pair(p.first-1, p.second)); dir[p.first-1][p.second]=4;
    }
    cout << d[h_x][h_y] << endl;
    return 0;
}
/*
    //bfs
    stack< pair<int,int> > s;
    s.push(make_pair(h_x, h_y));
    cout << "pushed in stack=" << h_x << ", " << h_y << endl;
    while (!s.empty()) {
	cout << "doing..\n";
	pair<int, int> p = s.top(); s.pop();
	if (!visited[p.first][p.second]) {
	    visited[p.first][p.second]=true;
	    cout << "from stack= " << p.first << ", " << p.second;
	    if (p.first==l_x && p.second==l_y) cout << "reached..\n";
	    if (p.first-1>=0 && arr[p.first-1][p.second]!='*') s.push(make_pair(p.first-1, p.second));
	    if (p.second+1<c && arr[p.first][p.second+1]!='*') s.push(make_pair(p.first, p.second+1));
	    if (p.first+1<r && arr[p.first+1][p.second]!='*') s.push(make_pair(p.first+1, p.second));
	    if (p.second-1>=0 && arr[p.first-1][p.second]!='*') s.push(make_pair(p.first, p.second-1));
	}
    }
    */
