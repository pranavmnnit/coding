#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

const ull mod = 1e9+7;

ull gcd (ull a, ull b) {
    cout << "a=" << a << ",b=" << b << endl;
    if (!a) return b;
    if (!b) return a;
    if (a>b) return gcd(a%b, b);
    return gcd(a,a%b);
}

int main() {
    int T;
    ull a, b, c;
    cin >> T;
    while (T--) {
	cin >> a >> b >> c;
	ull gc = gcd(a, gcd(b, c));
	cout << gc << " " << (a/gc)*(b/gc)*(c/gc) << endl;
    }
    return 0;
}
