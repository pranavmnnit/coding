#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int sz = static_cast<int>(str.size());
    for (int i = sz-1; i > 0; --i) {
	if (str[i]-'0' > 4) {
	    str[i] = 9 - (str[i] - '0') + '0';
	}
    }
    if ((str[0] != '9') && (str[0] > '4')) {
	str[0] = 9 - (str[0] - '0') + '0';
    }
    cout << str << endl;
    return 0;
}
