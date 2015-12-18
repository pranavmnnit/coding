#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define tr(obj, it) for(typeof(obj.begin()) it = obj.begin(); it != obj.end(); ++it)
#define SIZE 100010
#define END (1L<<32)
#define DIFF 0.5
#define ull unsigned long long

using namespace std;

ull arr[SIZE];
ull tree[SIZE];
ull sum[320];
ull temp2[320][SIZE+1];
vector< pair< ull, ull> > range;
ull K;

inline void BITree(ull N) {
    for (ull i=1; i<=N; i++) {
	ull upto = (i & (i-1));
	tree[i] = arr[i]; ull idx = i-1;
	while (idx>upto) {
	    tree[i] += tree[idx];
	    idx = (idx & (idx-1));
	}
    }
}

inline void update(ull idx, ull val, ull N) {
    ull nob = (N/K);
    //update sqrt
    if (K*K != N) ++nob;

    for (ull bucket=0; bucket<nob; ++bucket) {
	sum[bucket] = sum[bucket] + temp2[bucket][idx]*(val-arr[idx]);
    }

    //update BITree
    ull id2 = idx;
    while (idx <= N) {
	tree[idx] = (tree[idx]-arr[id2]+val);
	idx += (idx & -idx);
    }
    arr[id2] = val;
}

inline ull retrange(ull x, ull y) {
    ull ans = 0;
    while (y) {
	ans += tree[y];
	y = (y&(y-1));
    }
    --x;
    while (x) {
	ans -= tree[x];
	x = (x&(x-1));
    }
    return ans;
}


ull query(ull f1, ull f2, ull N) {
    --f1; --f2; ull su=0;
    ull rb=f2/K, lb=f1/K;
    bool same=(lb==rb?true:false);

    for (ull b=lb+1; b<rb; ++b) {
	su += sum[b];
    }
    ++f1; ++f2;
    for (ull fun=f1; (fun<=(1+lb)*K) && (fun<=f2); ++fun) {
	su += retrange(range[fun].first, range[fun].second);
    }
    if (!same) {
	for (ull fun=rb*K+1; (fun<=f2) && (fun<=N); ++fun) {
	    su += retrange(range[fun].first, range[fun].second);
	}
    }
    return su;
}

void createsqrt(ull N) {
    ull i;
    for (i=0; (i+1)*K<N; ++i) {
	for (ull j=0; j<K; j++) {
	    sum[i] += retrange(range[j+i*K+1].first, range[j+i*K+1].second);
	    temp2[i][range[j+i*K+1].first]++; temp2[i][range[j+i*K+1].second+1]--;
	}
	for (ull k=1; k<=N; ++k) {
	    temp2[i][k] += temp2[i][k-1];
	}
    }
    ull idx=i*K;
    for (;idx<N;++idx) {
	sum[i] += retrange(range[idx+1].first, range[idx+1].second);
	temp2[i][range[idx+1].first]++; temp2[i][range[idx+1].second+1]--;
    }
    for (ull k=1; k<=N; ++k) {
	temp2[i][k] += temp2[i][k-1];
    }
}

int main() {
    ull N, x, y, type, f1, f2, Q;
    range.push_back(make_pair(-1,-1));

    scanf("%llu", &N);
    range.reserve(N);
    double K1 = sqrt(N);
    if (K1-(ull)K1 > DIFF) { ++K1; }
    K = (ull)K1;

    for (ull i=1; i<=N; ++i) {
	scanf("%llu", &arr[i]);
    }
    for (ull i=1; i<=N; ++i) {
	scanf("%llu %llu", &x, &y);
	range.push_back(make_pair(x,y));
    }
    BITree(N);
    createsqrt(N);
    scanf("%llu", &Q);
    while (Q--) {
	scanf("%llu %llu %llu", &type, &f1, &f2);
	if (type == 1) {
	    update(f1, f2, N);
	} else if (type == 2) {
	    printf("%llu\n",query(f1, f2, N));
	}
    }
    return 0;
}
