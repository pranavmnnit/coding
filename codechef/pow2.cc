#include <iostream>
const unsigned long long mod = 1e9+7;

using namespace std;

//mod
unsigned long long pow2(long long N) {
    if (N == 0) return 1;
    unsigned long long ans = 1, a = 2;
    while (N) {
	if (N%2) ans = (a*ans)%mod;
	a = (a*a)%mod;
	N /= 2;
    }
    cout << "a=" << a << endl;
    return ans;
}

int main() {
    int a;
    cin >> a;
    cout << pow2(a);
    return 0;
}
