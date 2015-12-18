#include <iostream>
using namespace std;

int main() {
    int T,N,K;
    int arr[100010] = {0};
    long total,best;

    cin >> T;
    while (T--) {
	total = best = 0;
	cin >> N >> K;
	for (int i=0; i<N; ++i) {
	    cin >> arr[i];
	}
	for (int i=0; i<K; ++i) {
	    best += arr[i];
	}
	total = best;
	for (int i=0; (i+K-1)<N; ++i) {
	    total -= arr[i]; total += arr[i+K];
	    if (total > best) { best = total; }
	}
	cout << best << endl;
    }
    return 0;
}

