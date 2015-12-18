#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long t, d;
    long long n, k, num, prev, i;
    cin >> t;
    while (t--) {
	cin >> n >> k;
	d=i=1; prev=0;
	while (k>9*d*i) { prev+=(9*d*i); d*=10; ++i; }
	k-=prev;
	//cout << "k= " << k << endl;
	num=((k-1)/i)+d;
	//cout << "num= " << num << endl;
	k=(k+1)%i;
	//cout << "remained= " << k << endl;
	num/=(pow(1.0*10, 1.0*(i-k-1)));
	//cout << "number=" << num << endl;
	cout << num%(10) << endl;
    }
    return 0;
}
