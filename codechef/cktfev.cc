#include <iostream>
using namespace std;

int main() {
    int t, o, r, s;
    cin >> t;
    while (t--) {
	cin >> o >> r >> s;
	printf("%.2f\n", ((1.0*o*r)+s)/(o+1));
    }
    return 0;
}
