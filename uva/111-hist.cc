#include <iostream>
using namespace std;

int main() {
    int N;
    //int order[21];
    int idx[21];
    int student[21];
    int dp[21];
    int num, cnt=1, maxim=1;
    cin >> N;
    for (int i=1; i<=N; i++) {
	cin >> num;
	idx[i] = num-1;
    }
    while (cin >> num) {
	student[num-1] = cnt;
	cnt++;
	if (cnt <= N) { continue; }
	cnt = 1;
	maxim = 1;
	fill_n(dp, 20, 1);
	for (int i=1; i<N; ++i) {
	    for (int j=i-1; j>=0; --j) {
		if (idx[student[i]] > idx[student[j]]) {
		    dp[i] = max(dp[i], dp[j]+1);
		    maxim = (dp[i] > maxim) ? dp[i] : maxim;
		}
	    }
	}
	cout << maxim << endl;
    }
    return 0;
}
