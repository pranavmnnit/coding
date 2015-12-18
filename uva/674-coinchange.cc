#include <iostream>
using namespace std;

int coin[] = {1, 5, 10, 25, 50};

int main() {
    int dp[7490] = {0};
    dp[0] = 1;

    for (int j=0; j<5; j++) {
	for (int i=1; i<=7489; ++i) {
	    if (i - coin[j] >= 0) {
		dp[i] += dp[i - coin[j]];
	    }
	}
    }
    int num;
    while (cin >> num) {
	cout << dp[num] << endl;
    }
    return 0;
}
