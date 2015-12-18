#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long r, x, y, xx, yy;
    cin >> r >> x >> y >> xx >> yy;
    double dist = sqrt((xx - x)*(xx - x) + (yy - y)*(yy - y));
    long long res=ceil(dist/(2*r));
    cout << res << endl;
    return 0;
}
