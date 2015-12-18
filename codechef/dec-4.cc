#include <iostream>
#include <vector>
#define ll long long
#define ull unsigned long long
#define tr(ob, it) \
    for(typeof(ob.begin()) it=ob.begin(); it!=ob.end(); ++it)
using namespace std;

const ll mod = 1e9+7;

ll A[1001];
ll num[101][101];

ll range(int a, int b) {
    if (a+1>b) return 1;
    if (num[a][b]) return num[a][b];
    int i,j;
    for (i=a; i<b; ++i) {
	for (j=i+1; j<=b; ++j) {
	    if (A[j]==-A[i] && A[j]>0) {
		num[a][b] += (range(i+1, j-1)*range(j+1, b));
		num[a][b] %= mod;
	    }
	}
    }
    num[a][b]++;
    num[a][b] %= mod;
    return num[a][b];
}

int main() {
    int N;
    ll a;
    cin >> N;
    for (int i=0; i<N; ++i) {
	cin >> A[i];
    }
    cout << range(0, N-1) << endl;

    return 0;
}
