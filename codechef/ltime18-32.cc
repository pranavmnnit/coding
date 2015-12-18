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

ull mypow(ull num, ull po) { //return (num^num)%MOD
    ull res = 1;
    while (po) {
	if (po%2) {
	    res *= num;
	    res %= MOD;
	    --po;
	} else {
	    num *= num;
	    num %= MOD;
	    po /= 2;
	}
    }
    return res;
}

int main() {
    int T, N;
    set<ull> S1, S2;
    map<ull, pair<int, int> > M;
    ull arr[1001], sim[1001][1001], ind[1001], least=0, least1=0;
    bool done[1001] = {false};
    scanf("%d", &T);
    while (T--) {
	set<ull> empty; map<ull, pair<int, int> > em;
	S1.swap(empty); swap(M, em); S2.swap(S1);
	memset(arr, 0, sizeof(arr));
	memset(done, 0, sizeof(done));
	memset(sim, 0, sizeof(sim[0][0])*1001*1001);
	least = least1 = 0;
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
	    scanf("%llu", arr+i);
	}
	for (int i=0; i<N; ++i) {
	    for (int j=i+1; j<N; ++j) {
		sim[j][i] = sim[i][j] = min(mypow(arr[i], arr[j]), mypow(arr[j], arr[i]));
	    }
	}
    }
    return 0;
}
