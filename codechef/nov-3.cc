#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double d, N;
    long long X, K, k2;
    int T;
    cin >> T;
    while (T--) {
	N = 0;
	cin >> X >> K;
	k2 = K;
	K |= (K >> 1);
	K |= (K >> 2);
	K |= (K >> 4);
	K |= (K >> 8);
	K |= (K >> 16);
	K |= (K >> 32);
	long long a = K - (K >> 1);
	long long a2 = a;
	while (a) {
	    N++;
	    a >>= 1;
	}
	d = X/pow(2.0, N)*(1 + (k2-a2)*2);
	cout << fixed << d << endl;
    }
    return 0;
}
