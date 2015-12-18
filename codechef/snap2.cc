#include <iostream>
using namespace std;

int maxstep(int N, int K) {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
	ans += i;
	if (ans == K) ans--;
    }
    return ans;
}

int main() {
    int t, n, b;
    cin >> t;
    while (t--) {
	cin >> n >> b;
	cout << maxstep(n, b) << endl;
    }
    return 0;
}
