#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N, M, a;
    cin >> T;
    while (T--) {
	cin >> N >> a >> M;
	int k = (a+(M%N))%N;
	cout << (k?k:N) << endl;
    }
    return 0;
}
