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
	if (Y%2 == 0) {
	    if (Y > 0) {
		if ((X >= -Y) && (X < Y)) {
		    cout << "YES" << endl;
		    continue;
		}
	    } else {
		if ((X >= Y) && (X <= -(Y-1))) {
		    cout << "YES" << endl;
		    continue;
		}
	    }
	}
	if (X > 0) {
	    if (X%2 != 0) {
		if ((Y >= -(X-1)) && (Y <= (X+1))) {
		    cout << "YES" << endl;
		    continue;
		} else {
		    cout << "NO" << endl;
		    continue;
		}
	    } else {
		cout << "NO" << endl;
		continue;
	    }
	} else {
	    if (X%2 == 0) {
		if ((Y >= X) && (Y <= -X)) {
		    cout << "YES" << endl;
		    continue;
		} else {
		    cout << "NO" << endl;
		    continue;
		}
	    } else {
		cout << "NO" << endl;
		continue;
	    }
	}
    }
    return 0;
}
