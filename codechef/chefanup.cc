#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    long long n, k, l;
    long long ans[10010];
    cin >> t;
    while (t--) {
	cin >> n >> k >> l;
	for (int i = 0; i < n; ++i) {
	    ans[i] = (((l-1)/(long long)pow(k, i))%k) + 1;
	}
	for (int i = n-1; i > 0; --i) {
	    cout << ans[i] << " ";
	}
	cout << ans[0] << endl;
    }
    return 0;
}
