#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q, n1, n2, n3;
    cin >> Q;
    while (Q--) {
	cin >> n1 >> n2 >> n3;
	if (n1%2==0 && n2%2==0 && n3%2==0) {
	    cout << "Aishwarya" << endl;
	} else {
	    cout << "Ashima" << endl;
	}
    }
    return 0;
}
