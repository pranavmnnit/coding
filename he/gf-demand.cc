#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int l = str.size();
    int Q;
    long long a,b;
    cin >> Q;
    while (Q--) {
	cin >> a >> b;
	long long a1 = a%l; if (!a1) a1 = l;
	long long b1 = b%l; if (!b1) b1 = l;
	if (str[a1-1] == str[b1-1]) {
	    cout << "Yes" << endl;
	} else {
	    cout << "No" << endl;
	}
    }
    return 0;
}
