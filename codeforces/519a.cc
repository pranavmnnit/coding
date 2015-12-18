#include <iostream>
#include <vector>
using namespace std;

int main() {
    int p1 = 0, p2 = 0;
    char ch;
    vector<string> b(10);
    for (int i = 0; i < 8; ++i) {
	cin >> b[i];
    }
    for (int i = 0; i < 8; ++i) {
	for (int j = 0; j < 8; ++j) {
	    ch = b[i][j];
	    if (ch == '.') continue;
	    else if (ch == 'q') p2 += 9;
	    else if (ch == 'r') p2 += 5;
	    else if (ch == 'b') p2 += 3;
	    else if (ch == 'n') p2 += 3;
	    else if (ch == 'p') p2 += 1;
	    else if (ch == 'Q') p1 += 9;
	    else if (ch == 'R') p1 += 5;
	    else if (ch == 'B') p1 += 3;
	    else if (ch == 'N') p1 += 3;
	    else if (ch == 'P') p1 += 1;
	}
    }
    cout << "p1=" << p1  << "p2=" << p2 << endl;
    if (p1 > p2) {
	cout << "White" << endl;
    } else if (p2 > p1) {
	cout << "Black" << endl;
    } else {
	cout << "Draw" << endl;
    }
    return 0;
}
