#include <iostream>
using namespace std;

int seg[3000030], arr[1000010];

void init(int node, int l, int r) {
    if (l > r) return;
    if (l == r) {
	seg[node] = l; return;
    }
    init(2*node, l, l+(r-l)/2);
    init(2*node+1, l+(r-l)/2+1, r);
    if (arr[seg[2*node]] < arr[seg[2*node+1]]) seg[node] = seg[2*node];
    else seg[node] = seg[2*node+1];
}

int segmin(int node, int l, int r, int b, int e) {
    if (b > r || e < l) return -1;
    if (l >= b && r <= e) return seg[node];
    int L = segmin(node*2, l, l+(r-l)/2, b , e);
    int R = segmin(node*2+1, l+(r-l)/2+1, r, b, e);
    if (L == -1) return R;
    if (R == -1) return L;
    if (arr[L] < arr[R]) return L;
    else return R;
}

int main() {
    int n, c, A, B;
    scanf("%d", &n);
    for (int i = 1; i <= n ;++i) scanf("%d", arr+i);
    init(1, 1, n);
    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
	scanf("%d %d", &A, &B);
	printf("%d\n", segmin(1, 1, n, A, B));
    }
    return 0;
}
