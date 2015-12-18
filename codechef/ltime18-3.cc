#include <iostream>
#include <cstring>
#include <set>
#include <map>
#define ull unsigned long long
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))
#define tr(obj, it) \
    for(typeof(obj.begin()) it = obj.begin(); it != obj.end(); ++it)

using namespace std;

const ull MOD = 1e9+7;
typedef map<ull, pair<int,int> > Map;

ull mypow(ull num, ull po) { //return (num^num)%MOD
    ull res = 1;
    while (po) {
	if (po%2) { res *= num; res %= MOD; --po; }
	else { num *= num; num %= MOD; po /= 2; }
    }
    return res;
}

int main() {
    int T, N;
    ull arr[1001], sim[1001][1001];
    bool set1[1001], set2[1001];
    bool done[1001] = {false};
    ull max_a, max_b; int idx_a, idx_b;
    ull s1, s2;
    scanf("%d", &T);
    while (T--) {
	max_a=max_b=idx_a=idx_b=0;
	memset(set1, 0, sizeof(set1));
	memset(set2, 0, sizeof(set2));
	memset(sim, 0, sizeof(sim[0][0])*1001*1001);
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
	    scanf("%llu", arr+i);
	}
	for (int i=0; i<N; ++i) {
	    for (int j=i+1; j<N; ++j) {
		sim[j][i] = sim[i][j] = min(mypow(arr[i], arr[j]), mypow(arr[j], arr[i]));
		if (sim[i][j] > max_a) { max_a = sim[i][j]; idx_a = i; idx_b = j; }
	    }
	}
	set1[idx_a] = 1; set2[idx_b] = 1;
	max_a=max_b=0;
	int i;
	for (i=0; i<N; ++i) {
	    s1=s2=0;
	    if (!set1[i] && !set2[i]) {
		int j;
		for (j=0; j<N; ++j) {
		    if (set1[j] && sim[j][i]>s1) {
			s1 = sim[j][i];
		    }
		}
		int k;
		for (k=0; k<N; ++k) {
		    if (set2[k] && sim[k][i]>s2) {
			s2 = sim[k][i];
		    }
		}
		if (s1>s2) {
		    set2[i]=true;
		    max_b = max(max_b, s2);
		} else {
		    set1[i]=true;
		    max_a = max(max_a, s1);
		}
	    }
	}
	printf("%llu\n", max(max_a, max_b));
    }
    return 0;
}
