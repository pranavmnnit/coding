#include <iostream>
using namespace std;

long long tree[1000010];
long long A[1000010];

void update(long long idx, long long val, long long n) {
    while (idx<=n) {
	tree[idx]+=val;
	idx+=(idx&-idx);
    }
}

long long upto(long long idx, long long n) {
    long long sum=0;
    while (idx>0) {
	sum+=tree[idx];
	idx-=(idx&-idx);
    }
    return sum;
}

int main() {
    long long n, k, ma=-1;
    long long ans=0;
    scanf("%lld %lld", &n, &k);
    if (n<3) { printf("0\n"); return 0; }
    for (long long i=1; i<=n; ++i) {
	scanf("%lld", A+i);
	if (A[i]>ma) ma=A[i];
    }
    ma=1000010;
    update(A[n], 1, ma);
    for (long long j=n-1; j>=2; --j) {
	for (long long i=j-1; i>=1; --i) {
	    ans+=upto(k/(A[i]*A[j]), ma);
	}
	update(A[j], 1, ma);
    }
    printf("%lld\n", ans);
    return 0;
}
