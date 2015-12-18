#include <iostream>
using namespace std;

void failure(string &str, int sz, int* fail) {
    fail[0] = fail[1] = 0;
    for (int i = 2; i < sz; ++i) {
	int t = fail[i-1];
	while(1) {
	    if (str[i-1] == str[t]) {
		fail[i] = fail[i-1]+1;
		break;
	    }
	    if (t == 0) {
		fail[i] = 0;
		break;
	    }
	    t = fail[t];
	}
    }
}

int main() {
    string str = "ABAABA";
    int fail[10] = {0};
    failure(str, 6, fail);
    for (int i=0; i<=6; ++i) {
	cout << fail[i] << " " << endl;
    }
    return 0;
}
