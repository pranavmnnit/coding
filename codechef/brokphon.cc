#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t, n;
    int *arr = new int[100010];
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
	    scanf("%d", arr+i);
	}
	int last = -1, ans = 0;
	for (int i = 1; i < n; ++i) {
	    if (arr[i] != arr[i-1]) {
		ans += ((i - last == 1) ? 1 : 2);
		last = i;
	    }
	}
	printf("%d\n", ans);
    }
    delete []arr;
    return 0;
}
