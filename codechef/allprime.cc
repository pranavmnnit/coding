#include <iostream>
#include <vector>
using namespace std;

void fun() {
    long n = 1000000010;
    vector<bool> isPrime(n, 1);
    for (int i = 2; i <= n; ++i) {
	if (isPrime[i]) {
	    for (int j = 2*i; j <= n; j += i) isPrime[j] = false;
	}
    }

    for (int i = 2; i <= n; ++i) {
	if (isPrime[i]) {
	    cout << i << endl;
	}
    }
}

int main() {
    fun();
    return 0;
}
