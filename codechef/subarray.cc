#include <iostream>
#include <cstring>
#include <stack>
#define max(a, b) ((a)>(b)?(a):(b))
using namespace std;

char a[100010];
long long num[100010];
long long dp[100010];
long long match[100010];
long long sum[100010];

inline char opposite(char ch) {
    if (ch == ')') return '(';
    if (ch == '}') return '{';
    if (ch == ']') return '[';
    if (ch == '>') return '<';
    return '.';
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	scanf("%s", a);
	memset(dp, 0, n*(sizeof(dp[0])));
	sum[0] = 0;
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
	    scanf("%lld", num+i);
	    sum[i+1] = sum[i] + num[i];
	    match[i] = -1;
	}
	stack<int> s;
	for (int i = 0; i < n; ++i) {
	    if (a[i] == '(' || a[i] == '{' || a[i] == '<' || a[i] == '[') s.push(i);
	    else if (!s.empty() && (a[s.top()] == opposite(a[i]))) {
		match[i] = s.top();
		s.pop();
	    } else s.push(i);
	}
	long long ma = 0;
	//dp[i] = max proper ending at index i
	for (int i = 1; i < n; ++i) {
	    if (match[i] > -1) { //proper bracket matach at index i
		if (((match[i] > 0) ? dp[match[i] - 1] : 0) + (sum[i + 1] - sum[match[i]]) > 0) {
		    /*
		       ..................
		                ^ ^   ^
			   (m[i]-1) m[i] i
		     */
		    dp[i] = ((match[i] > 0) ? dp[match[i] - 1] : 0) + (sum[i + 1] - sum[match[i]]);
		}
		ma = ((dp[i] > ma) ? dp[i] : ma);
	    }
	}
	printf("%lld\n", ma);
    }
    return 0;
}
