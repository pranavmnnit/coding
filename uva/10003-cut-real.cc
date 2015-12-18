#include <iostream>
#include <limits>
using namespace std;

int dp[1001][1001];
const int MAXIM = 2147483647;

int F(int beg, int end, int* cnt, int cntsz) {
    if (beg >= end) return 0;
    if (dp[beg][end] >= 0) {
	return dp[beg][end];
    }

    int mins = MAXIM;
    int left = 0;
    for (int i=0; i<cntsz; i++) {
	left = F(beg, cnt[i], cnt, cntsz-1) + F(cnt[i], end, cnt+1, cntsz-1) + (end-beg);
	int k = ((mins - left) >> (sizeof(int)*8 - 1));
	mins -= (~k & (mins - left));
    }
    return (dp[beg][end] = mins);
}

int main() {
    int N;
    int inp, noc, arr[51];
    while (cin >> N) {
	if (N == 0) break;
	cin >> noc;
	if (noc <= 0) {
	    cout << "The minimum cutting is " << 0 << "." << endl;
	    continue;
	}
	for (int i=0; i<=N; i++) {
	    for (int j=0; j<=N; j++) {
		dp[i][j] = -1;
	    }
	}
	for (int i=0; i<noc; i++) {
	    cin >> arr[i];
	}
	dp[0][arr[0]] = 0;
	dp[arr[noc-1]][N] = 0;
	if (noc > 1) {
	    dp[0][arr[1]] = arr[1];
	    dp[arr[noc-2]][N] = N - arr[noc-2];
	} else {
	    dp[0][N] = N;
	}
	for (int i=1; i<noc; i++) {
	    dp[arr[i-1]][arr[i]] = 0;
	}
	for (int i=2; i<noc; i++) {
	    dp[arr[i-2]][arr[i]] = arr[i] - arr[i-2];
	}
	cout << "The minimum cutting is " << F(0, N, arr, noc) << "." << endl;
    }
    return 0;
}
