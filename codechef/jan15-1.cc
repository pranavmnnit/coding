#include <iostream>
using namespace std;

int main() {
    int T, N, A, B, K;
    unsigned long long ma;
    unsigned long long time[100010], profit[100010];
    cin >> T;
    while (T--) {
	ma=0;
	cin >> N >> K;
	for (int i=0; i<N; ++i) {
	    cin >> time[i];
	}
	for (int i=0; i<N; ++i) {
	    cin >> profit[i];
	    unsigned long long thiS=(K/time[i])*profit[i];
	    ma=thiS>ma?thiS:ma;
	}
	cout << ma << endl;
    }
    return 0;
}
