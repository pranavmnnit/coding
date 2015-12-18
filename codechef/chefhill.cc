#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, i;
    int A, B;
    int ma[100010]={0};
    int a[100010];
    stack<int> st;
    scanf("%d", &n);
    for (i=1; i<=n; ++i) {
	scanf("%d", &a[i]);
    }
    for (i=n; i>=1; --i) {
	while (!st.empty() && a[i]>=a[st.top()]) { st.pop(); }
	ma[i]=(st.empty()?n+1:st.top());
	st.push(i);
    }
    scanf("%d", &n);
    for (i=0; i<n; ++i) {
	scanf("%d %d", &A, &B);
	if (ma[A]>=B) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
