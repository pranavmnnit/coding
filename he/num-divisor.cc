#include <iostream>
using namespace std;

int main() {
    long n, t, nod;
    cin >> t;
    while (t--) {
	nod = 0;
	cin >> n;
	for (int i=2; i*i <= n; ++i) {
	    if (n%i == 0) {
		nod += 2;
	    }
	}
	cout << (nod+2) << endl;
    }
    return 0;
}
