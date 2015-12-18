#include <iostream>
#include <vector>
#define ull long long
#define pb push_back
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)
using namespace std;

const ull TEN6 = 1000000;
const ull MOD = 1000000007;

ull mypow(ull num, ull po) {
    ull result=1;
    while (po) {
        if (po%2==0) {
            num *= num;
            num %= MOD;
            po/=2;
        } else {
            result *= num;
            result %= MOD;
            po--;
        }
    }
    return result;
}

int main() {
    ull T, N, M, L, R;
    vector< vector<ull> > vec(TEN6+10);
    ull arr[TEN6+10];
    ull i, j;
    for (i=1; i<=1000; ++i) {
	for (j=i; j<=TEN6; j+=i) {
	    //cout << "doing vector..\n";
	    vec[j].pb(i);
	}
    }
    scanf("%llu", &T);
    while (T--) {
	//cout << "next test case..\n";
	scanf("%llu %llu %llu %llu", &N, &M, &L, &R);
	for (i=1; i<=TEN6; ++i) {
	    //cout << "In loop.. i= " << i << endl;
	    ull cnt=0;
	    tr(vec[i], it) {
		if (*it<=M) ++cnt;
	    }
	    arr[i]=mypow(cnt, N);
	    for (vector<ull>::iterator it=vec[i].begin(); it!=vec[i].end() && (*it)!=i; ++it) {
		arr[i]=(arr[i]-arr[*it]+MOD)%MOD;
	    }
	}
	ull cnt=0;
	for (i=L; i<=R; ++i) {
	    for (j=i; j<=TEN6; j+=i) {
		//cout << "up cnt..\n";
		cnt = (cnt+arr[j])%MOD;
	    }
	}
	printf("%llu\n", cnt);
    }
    return 0;
}
