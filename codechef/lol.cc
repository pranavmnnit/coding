#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 100010
int ft[MAXN];
 
void update(int idx,int val)
{
	for(;idx<MAXN;idx+=idx&-idx)
		ft[idx] += val;
}
 
int query(int idx)
{
	int sum = 0;
	for(;idx;idx-=idx&-idx)
		sum += ft[idx];
	return sum;
}
 
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			update(i,1);
		for(int i=1;i<=n;++i)
		    printf("tree[%d]=%d\t", i, ft[i]);
		printf("\n");
		for(int i=0;i<n;++i)
		{
			scanf("%d",&x);
			printf("%d ",query(x));
			update(x,-1);
		for(int i=1;i<=n;++i)
		    printf("tree[%d]=%d\t", i, ft[i]);
		printf("\n");
		}
		printf("\n");
	}
	return 0;
} 
