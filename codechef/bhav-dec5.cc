#include <iostream>
#include <queue>
#include <vector>
using namespace	std;

int parent[10001],king;
int dist[10001]={0};
vector<vector<int> > v(10001);
vector<vector<int> > product(10001);

void bfs(){
	int dt=0;
	queue<int> q;
	q.push(king);
	parent[king] = king;
	dist[king] = 0;
	while(!q.empty())
	{	int top=q.front();
		q.pop();
		printf("top%d\n",top);
		dt++;
		int sz=v[top].size();
		for(int i=0;i<sz;i++)
		{
			q.push(v[top][i]);
			dist[v[top][i]]=dt;
			parent[v[top][i]]=top;
		}
	}
}

int main(){
	int n,k,q,x,y;
	scanf("%d%d%d",&n,&k,&king);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		product[x].push_back(i);
	}
	bfs();
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&y);
	}
return 0;
}
