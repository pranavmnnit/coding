#include <iostream>
#define ll unsigned long long
using namespace std;

const long long mod=1e9+7;

ll arr[1001][1001];

ll now(int idx, int M, int N, int s_d, int s_m) {
    if (s_d < s_m*M) { return 0; }
    if (idx == N) { return 1; }
    //if (arr[s_d][s_m]) { return arr[s_d][s_m]; }
    ll d = now(idx+1, M, N, s_d+1, s_m);
    ll m = now(idx+1, M, N, s_d, s_m+1);
    return (arr[s_d][s_m] = ((d+m)%mod));
}

int main() {
    int T, N, M;
    cin >> T;
    while (T--) {
	memset(arr, 0, sizeof(arr[0][0])*1001*1001);
	cin >> N >> M;
	cout << now(0, M, N, 0, 0) << endl;
    }
    return 0;
}
