#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long pos[100010];
map<long long, long long> M;

int main() {
    long long n, m, a, b, k, ans = 0;
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; ++i) {
	cin >> pos[i];
	M[pos[i]] = i;
    }
    for (long long i = 1; i <= m; ++i) {
	cin >> a;
	b = a;
	ans += ((M[a]-1)/k) + 1;
	if (M[a] > 1) {
	    b = pos[M[a]-1];
	    pos[M[a]-1] = pos[M[a]-1] ^ pos[M[a]] ^ (pos[M[a]] = pos[M[a]-1]);
	    M[a]--; M[b]++;
	}
    }
    cout << ans << endl;
}
