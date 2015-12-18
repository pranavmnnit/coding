#include <iostream>
using namespace std;

int main() {
    string str;
    long arr[100010] = {0};
    long n, a;
    cin >> str;
    cin >> n;
    while (n--) {
	cin >> a; --a;
	arr[a]++;
    }
    long sz = static_cast<long>(str.size());
    for (long i = 1; i < sz/2; ++i) {
	arr[i] += arr[i-1];
    }
    for (long i = 0; i < sz/2; ++i) {
	if (arr[i]%2 == 1) {
	    str[sz-i-1] = (str[i] ^ str[sz-i-1] ^ (str[i] = str[sz-i-1]));
	}
    }
    cout << str << endl;
    return 0;
}
