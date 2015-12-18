#include <iostream>
#include <set>
#define INF 9999999
using namespace std;

int main() {
    double n, x0, y0, x, y;
    set<double> s;
    cin >> n >> x0 >> y0;
    for (int i = 0; i < n; ++i) {
	cin >> x >> y;
	if (x - x0) {
	    s.insert((double)(y-y0)/(x-x0));
	} else {
	    s.insert(INF);
	}
    }
    cout << s.size() << endl;
    return 0;
}
