#include <iostream>
#define tr(object, it) \
    for (typeof (object.begin()) it = object.begin(); it != object.end(); ++it)

const int mod=1000000007;

using namespace std;

int main() {
    int T, N, M, x;
    int a[1001];
    bool b[1001];
    unsigned long long ma;
    scanf("%d", &T);
    for (int t=1; t<=T; ++t) {
	bool ans[1025]={0}; ma=0;
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; ++i) {
            scanf("%d", &a[i]);
	}
	for (int i=0; i<M; ++i) {
            scanf("%d", &x);
	    b[x]=true;
	}
	ans[0]=1;
	for (int i=0; i<N; ++i) {
	    for (int j=0; j<=1024; ++j) {
		if (ans[j]) {
		    ans[j^a[i]]=1;
		    if (!b[j^a[i]]) { ++ma; ma %= mod; }
		}
	    }
	}
        printf("Case %d: %d\n", t, ma);
    }
    return 0;
}
