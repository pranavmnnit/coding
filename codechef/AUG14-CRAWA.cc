#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    long X, Y;
    cin >> T;
    while (T--) {
	cin >> X >> Y;
	if ((X == 0 || X == 1) && Y == 0) {
	    cout << "YES" << endl;
	    continue;
	}
	if (X > 0 && Y > 0) { // 1st quad
	    if ((X%2 != 0) && (Y <= X+1)) {
		cout << "YES" << endl;
		continue;
	    } else if ((Y%2 == 0) && (X < Y)) {
		cout << "YES" << endl;
		continue;
	    } else {
		cout << "NO" << endl;
	    }
	} else if (X > 0 && Y < 0) { //4th quad
    }
    return 0;
}
