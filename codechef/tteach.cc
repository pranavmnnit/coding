#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long vec[100010];

inline int isPossible(long long C, long long dist, long long sz) {
    long long d=0, cnt=1;
    long long vitr = 1;
    for (; vitr < sz; ++vitr) {
	d+=(vec[vitr]-vec[vitr-1]);
	if (d<dist) continue;
	else {
	    d=0;
	    ++cnt;
	    if (cnt==C) return 1;
	}
    }
    return 0;
}

int main() {
    long long N, a, C, ans=-1;
    long long t;
    scanf("%lld", &t);
    while (t--) {
	scanf("%lld %lld", &N, &C);
	ans = -1;
	for (long long i=0; i<N; ++i) {
	    scanf("%lld", vec+i);
	}
	sort(vec, vec+N);
	long long min=0;
	long long max=2*(vec[N-1] - vec[0]);
	long long mid;
	while (max>=min) {
	    mid=(min+max)/2;
	    if (isPossible(C, mid, N)) {
		ans=(mid>ans?mid:ans);
		min=mid+1;
	    } else {
		max=mid-1;
	    }
	}
	printf("%lld\n", ans);
    }
    return 0;
}
