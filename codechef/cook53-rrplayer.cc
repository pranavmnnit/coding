#include <iostream>
using namespace std;

int main() {
    int T, N;
    double ans;
    cin >> T;
    while (T--) {
	cin >> N;
	ans = N;
	for (int i=1; i<N; ++i) {
	    ans += ((double)i/(N-i));
	}
	cout << ans << endl;
    }
    return 0;
}
