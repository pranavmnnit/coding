#include <stdio.h>
#define ll long long
#define ABS(a)	((a)<0?(-a):(a))

ll left[500010];
ll right[500010];
ll arr[500010];
ll cnt[500010];

int main() {
    ll N, i, j;
    ll sum=0, ans=0, req=0;
    scanf("%lld", &N);
    left[0]=0;
    for (i=1; i<=N; ++i) {
	scanf("%lld", &arr[i]);
	sum+=arr[i];
	left[i]=left[i-1]+arr[i];
    }
    if ((ABS(sum)%3)!=0) { printf("0\n"); goto done; }
    else req=sum/3;
    right[N]=arr[N];
    if (right[N]==req) cnt[N]=1;
    for (i=N-1; i>=1; --i) {
	right[i]=right[i+1]+arr[i];
	if (right[i]==req) cnt[i]=cnt[i+1]+1;
	else cnt[i]=cnt[i+1];
    }
    for (i=1; i<N-1; ++i) {
	if (left[i]==req) {
	    ans+=cnt[i+2];
	}
    }
    printf("%lld\n", ans);
done:
    return 0;
}
