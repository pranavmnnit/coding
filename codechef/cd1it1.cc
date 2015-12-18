#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long n;
    cin >> n;
    long a[n+1];
    for (long i=0; i<n; ++i) {
	cin >> a[i];
    }
    sort(a, a+n);
    --n;
    cout << a[n/2] << endl;
    return 0;
}
