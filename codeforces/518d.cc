#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, t;
    double p;
    cin >> n >> p >> t;
    double ans = p;
    double p1 = (1-p);
    while (--t) {
	ans += (p1*p);
	p1 *= (1-p);
    }
    cout << ans << endl;
}
