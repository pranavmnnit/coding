#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define tr(obj, it) for (typeof((obj).begin()) it = (obj).begin(); it != (obj).end(); ++it)
#define isxfine(x) (((x) >= 0) && (x < n))
#define isyfine(y) (((y) >= 0) && (y < m))
using namespace std;

int cnt[1000010];

int main() {
    int n, m, q, index = 0, ans = 0;
    int arr[1001][1001];
    int num[1001][1001];
    int dir[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    memset(num, 0, 1001*1001*sizeof(int));
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
	    scanf("%d", *(arr+i)+j);
	}
    }

    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
	    if (arr[i][j]) ++ans;
	    if (!arr[i][j] || num[i][j]) continue;
	    else {
		index++;
		num[i][j] = index;
		cnt[index]++;
		queue< pair<int, int> > q;
		q.push(make_pair<int, int>(i, j));
		while (!q.empty()) {
		    pair<int, int> p = q.front();
		    q.pop();
		    for (int k = 0; k < 4; ++k) {
			int _x = p.first + dir[k][0];
			int _y = p.second + dir[k][1];
			if (isxfine(_x) && isyfine(_y) && !num[_x][_y] && arr[_x][_y]) {
			    num[_x][_y] = index;
			    cnt[index]++;
			    q.push(make_pair(_x, _y));
			}
		    }
		}
	    }
	}
    }

    int x, y;
    while (q--) {
	scanf("%d %d", &x, &y);
	--x; --y;
	if (arr[x][y]) {
	    ans -= cnt[num[x][y]];
	    cnt[num[x][y]] = 0;
	}
	printf("%d\n", ans);
    }

    return 0;
}
