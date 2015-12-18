#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T, N, a, cnt;
    bool count[100010];
    scanf("%d", &T);
    while (T--) {
	memset(count, 0, sizeof(count));
	cnt=0;
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
	    scanf("%d", &a);
	    if (!count[a]) { count[a]=true; cnt++; }
	}
	cout << cnt << endl;
    }
    return 0;
}
