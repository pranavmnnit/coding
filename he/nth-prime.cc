#include <iostream>
#include <vector>
#define tr(it, obj) for(typeof(obj.begin())it = obj.begin(); it != obj.end(); ++it)
using namespace std;

int main() {
    int t;
    bool isprime[10000010] = {false};

    for (int i=2; i<=10005; ++i) {
	if (isprime[i]) continue;
	for (int j=2; j*i<=10000010; ++j) {
	    isprime[i*j] = true;
	}
    }
    vector<int> primes;
    for (int i=2;i<=10000010; ++i) {
	if (!isprime[i]) {
	    primes.push_back(i);
	}
    }
    cin >> t;
    int a;
    while (t--) {
	cin >> a;
	cout << primes[a-1] << endl;
    }
    return 0;
}

