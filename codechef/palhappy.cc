#include <iostream>
using namespace std;

bool ispalin(const string& str) {
    int i = 0, j = static_cast<int>(str.size() - 1);
    while ((i <= j) && (str[i] == str[j])) {
	++i; --j;
    }
    if (i < j) return false;
    return true;
}

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
	cin >> str;
	int i = 0, j = static_cast<int>(str.size() - 1);
	while ((i <= j) && (str[i] == str[j])) {
	    ++i; --j;
	}
	if (i < j) {
	   if (ispalin(str.substr(i + 1, j - i - 1))) {
	       cout << "yes\n";
	   } else {
	       cout << "no\n";
	   }
	} else {
	    cout << "yes\n";
	}
    }
    return 0;
}
