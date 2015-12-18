#include <iostream>
#include <set>
#define LL long long
#define max(a, b) ((a)>(b)?(a):(b))
using namespace std;

int main() {
    LL dp[2001][2001]={{0}};
    LL weight[2001]={0};
    LL value[2001]={0};
    set<LL> nums;
    LL N, W;
    LL sum=0;
    cin >> N >> W;
    for (LL i=1; i<=N; ++i) {
	cin >> weight[i];
    }
    for (LL i=1; i<=N; ++i) {
	cin >> value[i];
    }
    for (LL i=1; i<=N; ++i) {
	for (LL w=1; w<=W; ++w) {
	    if (weight[i]>w) {
		dp[i][w] = dp[i-1][w];
	    } else if (dp[i-1][w-weight[i]]+value[i] > dp[i-1][w]) {
		dp[i][w] = dp[i-1][w-weight[i]]+value[i];
	    } else {
		dp[i][w] = dp[i-1][w];
	    }
	}
    }

    for (LL i=0; i<=N; ++i) {
	for (LL w=0; w<=W; ++w) {
	    cout << dp[i][w] << "\t";
	}
	cout << "\n";
    }

    LL i=N, j=W;
    while (i>0) {
	if (dp[i][j]-dp[i-1][j-weight[i]]==value[i]) {
	    cout << "picking.." << i << endl;
	    nums.insert(i); j-=weight[i]; --i;
	} else if (dp[i][j]>dp[i-1][j]) {
	    --j;
	} else {
	    --i;
	}
    }

    /*ITS WRONG!
    if (nums.size()==0) {
	cout << 0 << endl;
    } else if (nums.size()==1) {
	cout << value[*nums.begin()]*3 << endl;
    } else if (nums.size()==2) {
	cout << value[*nums.begin()]*2 + value[*(++nums.begin())]*3 << endl;
    } else {
	set<LL>::reverse_iterator it = nums.rbegin();
	sum+=value[*it]*3; ++it; sum+=value[*it]*2; ++it;
	for (; it != nums.rend(); ++it) {
	    sum+=value[*it];
	}
	cout << sum << endl;
    }*/
    return 0;
}
