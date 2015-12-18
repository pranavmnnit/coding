#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define tr(obj, it) \
    for(typeof (obj.begin()) it=obj.begin(); it!=obj.end(); ++it)
#define pb push_back
using namespace std;

int prev[10010]={0}, dist[10010]={0};
bool visited[10010]={0};

int LCA(int a, int b) {
    //cout << "a= " << a << ",b= " << b << endl;
    if (dist[a]>dist[b]) {
	while (dist[a]>dist[b]) a=prev[a];
    } else if (dist[a]<dist[b]) {
	while (dist[a]<dist[b]) b=prev[b];
    }
    while (a!=b) {
	a=prev[a]; b=prev[b];
    }
    //cout << "returning" << a << endl;
    return a;
}

int main() {
    int N,K,B,Qn;
    int a,b;
    map<int, vector<int> > Gr;
    map<int, vector<int> > prod;
    queue<int> Q;

    scanf("%d %d", &N, &K);
    scanf("%d", &B);
    for (int i=0; i<N-1; ++i) {
	scanf("%d %d", &a, &b);
	Gr[a].pb(b); Gr[b].pb(a);
    }
    for (int i=1; i<=N; ++i) {
	scanf("%d", &a);
	prod[a].pb(i);
    }
    //BFS, prev and dist
    Q.push(B); visited[B]=true; dist[B]=0;
    while (!Q.empty()) {
	int fr=Q.front(); Q.pop();
	tr (Gr[fr], it) {
	    if (!visited[*it]) {
		prev[*it]=fr;
		dist[*it]=dist[fr]+1;
		visited[*it]=true;
		Q.push(*it);
	    }
	}
    }
    scanf("%d", &Qn);
    for (int i=0; i<Qn; ++i) {
	scanf("%d %d", &a, &b);
	int d=-1, city=-1;
	if ((b<1)||(b>K)) {
	} else {
	    tr (prod[b], it) {
		int lca=LCA(a, *it);
		if ((dist[lca] == d) && (*it<city)) { city=*it; }
		else if (dist[lca] > d) { city=*it; d=dist[lca]; }
		//cout << "now, city=" << city << ",dist=" << d << endl;
	    }
	}
	printf("%d\n",city);
    }
    return 0;
}
