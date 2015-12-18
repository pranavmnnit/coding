#include <iostream>
#define ll long long
#define ABS(a)	((a)<0?(-a):(a))
using namespace std;

int main() {
    ll left[500010];
    ll right[500010];
    ll arr[500010];
    ll cnt[500010];
    ll N;
    ll sum=0, ans=0, req=0;
    scanf("%lld", &N);
    left[0]=0;
    for (ll i=1; i<=N; ++i) {
	scanf("%lld", &arr[i]);
	sum+=arr[i];
	left[i]=left[i-1]+arr[i];
    }
    //for (ll i=0; i<=N; ++i) {
    //    printf("for i= %lld, left= %lld\t", i, left[i]);
    //}
    //printf("\n");
    if ((ABS(sum)%3)!=0) { printf("0\n"); goto done; }
    else req=sum/3;
    printf("reqd=%lld\n", req);
    right[N]=arr[N];
    if (right[N]==req) cnt[N]=1;
    for (ll i=N-1; i>=1; --i) {
	right[i]=right[i+1]+arr[i];
	if (right[i]==req) cnt[i]=cnt[i+1]+1;
	else cnt[i]=cnt[i+1];
    }
    //for (ll i=0; i<=N; ++i) {
    //    printf("for i= %lld, cnt= %lld\t", i, cnt[i]);
    //}
    //printf("\n");
    for (ll i=1; i<N-1; ++i) {
	if (left[i]==req) {
	    //printf("found reqd at i=%lld, cnt at right=%lld\n", i, cnt[i+2]);
	    ans+=cnt[i+2];
	}
    }
    printf("%lld\n", ans);
done:
    return 0;
}
