#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    //int order[21];
    map<int, int> idx;
    int student[22];
    int dp[22];
    int num, cnt=1, maxim=1;
    cin >> N;
    for (int i=1; i<=N; i++) {
	cin >> num;
	idx[num-1] = i;
    }
    //for (int i=0; i<N; ++i) {
    //    cout << i << "=" << idx[i]<< endl;
    //}
    //cout << endl;
    while (cin >> num) {
	student[num-1] = cnt;
	cnt++;
	if (cnt <= N) { continue; }
	//for (int i=0; i<N; ++i) {
	//    cout << i << "=" << student[i] << endl;
	//}
	//cout << endl;
	cnt = 1;
	maxim = 1;
	fill_n(dp, 20, 1);
	for (int i=1; i<N; ++i) {
	    for (int j=i-1; j>=0; --j) {
		if (idx[student[i]] > idx[student[j]]) {
		    //cout << "idx[i]" << idx[i] << "idx[j]" << idx[j] << endl;
		    dp[i] = max(dp[i], dp[j]+1);
		    maxim = (dp[i] > maxim) ? dp[i] : maxim;
		}
	    }
	}
	//for (int i=0; i<N; i++) {
	//    cout << "%%" << dp[i] << endl;
	//}
	cout << maxim << endl;
    }
    return 0;
}
