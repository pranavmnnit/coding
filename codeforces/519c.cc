#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, m, ans;
    cin >> n >> m;
    ans = (n + m)/3;
    if (ans<n) ans = n;
    else if (ans<m) ans = m;
    cout << ans << endl;
}
