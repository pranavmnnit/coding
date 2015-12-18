#include <iostream>
using namespace std;

int main() {
    int n;
    int ma = 0;
    int z, x;
    string arr;
    cin >> n;
    while (n--) {
	cin >> arr;
	int sz = static_cast<int>(arr.size());
	ma = z = x = 0;
	for (int i = 1; i < sz; ++i) {
	    for (int j = i+1; j < sz; ++j) {
		for (int k = j+1; k < sz; ++k) {
		    z = x = 0;
		    string t = arr.substr(0, i);
		    if ((static_cast<int>(t.size()) > 1) && (t[0] == '0')) continue;
		    x = atoi(t.c_str());
		    if (x || static_cast<int>(t.size()) == 1)
		    z += x;

		    t = arr.substr(i, j-i);
		    if ((static_cast<int>(t.size()) > 1) && (t[0] == '0')) continue;
		    x = atoi(t.c_str());
		    z += x;

		    t = arr.substr(j, k-j);
		    if ((static_cast<int>(t.size()) > 1) && (t[0] == '0')) continue;
		    x = atoi(t.c_str());
		    z += x;

		    t = arr.substr(k, sz-k);
		    if ((static_cast<int>(t.size()) > 1) && (t[0] == '0')) continue;
		    x = atoi(t.c_str());
		    z += x;

		    if (z > ma) {
			ma = z;
		    }
		}
	    }
	}
	if (ma) cout << ma << endl;
	else cout << "unlucky\n";
    }
    return 0;
}
