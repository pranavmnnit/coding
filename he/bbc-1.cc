#include <iostream>
using namespace std;

int main() {
    int T, Z, N, K;
    int sub[1000001];
    cin >> T;
    while (T--) {
	cin >> Z >> N;
	cin >> K;
	for (int i=1; i<N; ++i) {
	    cin >> sub[i];
	    K &= sub[i];
	}
	if (!K || !(K&Z)) {
	    cout << "Yes" << endl;
	} else {
	    cout << "No" << endl;
	}
    }
    return 0;
}
