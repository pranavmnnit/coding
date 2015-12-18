#include <iostream>
#define ll long long
using namespace std;

ll arr[100010];

int main() {
    ll N, T;
    scanf("%lld", &T);
    while (T--) {
	scanf("%lld", &N);
	for (ll i=0; i<N; ++i) {
	    scanf("%lld", arr+i);
	}
	ll num=arr[0], cnt=1;
	for (ll i=1; i<N; ++i) {
	    if (arr[i]==num) ++cnt;
	    else if (--cnt==0) {
		num=arr[i];
		cnt=1;
	    }
	}
	cnt=0;
	for (ll i=0; i<N; ++i) {
	    if (arr[i]==num) ++cnt;
	}
	if (cnt>N/2) {
	    printf("%lld\n", num);
	} else {
	    printf("NO MAJOR\n");
	}
    }
    return 0;
}
