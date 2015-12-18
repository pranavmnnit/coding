#include <iostream>
using namespace std;

int main() {
    long long n, a;
    cin >> n;
    double sum=0;
    while (n--) {
	cin >> a;
	sum+=a;
    }
    cout << sum/2 << endl;
}
