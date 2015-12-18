#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(!a) return b;
    if(!b) return a;
    return ((a>b)?gcd(a%b,b):gcd(a,b%a));
}

int main() {
    int arr[100010];
    int N, Q, L, R, T;
    int left[10001], right[100010];
    scanf("%d", &T);
    while (T--) {
	scanf("%d %d", &N, &Q);
	for(int i=1; i<=N; ++i) {
	    scanf("%d", &arr[i]);
	}
	left[1]=arr[1]; right[N]=arr[N];
	for(int i=2; i<=N; ++i) {
	    left[i]=gcd(left[i-1], arr[i]);
	}
	for(int i=N-1; i>=1; --i) {
	    right[i]=gcd(right[i+1], arr[i]);
	}
	while(Q--) {
	    scanf("%d %d", &L, &R);
	    if (L==1) {
		printf("%d\n", right[R+1]);
	    } else if (R==N) {
		printf("%d\n", left[L-1]);
	    } else {
		printf("%d\n", gcd(left[L-1], right[R+1]));
	    }
	}
    }
    return 0;
}
