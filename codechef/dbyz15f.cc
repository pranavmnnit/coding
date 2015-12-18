#include <iostream>
#include <algorithm>
using namespace std;

inline int gcd(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    return (a > b ? gcd(a%b, b) : gcd(a, b%a));
}

int main() {
    int k;
    long long arr[1010];
    long n;
    cin >> k >> n;
    for (int i = 0; i < k; ++i) {
	cin >> arr[i];
    }

    if (k == 1) {
	cout << n*k << endl; return 0;
    }

    long long lcm = (1LL * arr[0] * arr[1])/(1LL * gcd(arr[0], arr[1]));
    for (int i = 2; i < k; ++i) {
	lcm = (1LL * lcm * arr[i])/(1LL * gcd(arr[i], lcm));
    }

    long long num = 0;
    for (int i = 0; i < k; ++i) {
	num += (1LL * lcm / arr[i]);
    }

    cout << (1LL * n * lcm)/(1LL * num) << endl;

    return 0;
}
