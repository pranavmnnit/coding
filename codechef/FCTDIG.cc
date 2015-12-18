#include <iostream>
#include <cmath>
using namespace std;

long long pre(int n) {
    double sum=0;
    if (n==0 || n==1) return 1;
    for (int i=1; i<=n; ++i) {
	sum+=(log(i)/log(10));
    }
    return ceil(sum);
}

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
	cin >> n;
	while (n--) {
	    cin >> x;
	    cout << pre(x) << ((n>0)?" ":"");
	}
	cout << endl;
    }
    return 0;
}
