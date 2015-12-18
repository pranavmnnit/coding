#include <iostream>
#include <map>
#define ull unsigned long long
using namespace std;

long getMaxAmount(long couponAmount) {
    map<ull, ull> m;
    if (couponAmount < 12) {
	return couponAmount;
    }
    if (m[couponAmount]) return m[couponAmount];
    else {
	return m[couponAmount] = max(couponAmount, getMaxAmount(couponAmount/2) + getMaxAmount(couponAmount/3) + getMaxAmount(couponAmount/4));
    }
}

int main() {
    int t;
    long n;
    cin >> t;
    while (t--) {
	cin >> n;
	cout << getMaxAmount(n) << endl;
    }
    return 0;
}
