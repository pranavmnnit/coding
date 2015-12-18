#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int arr[n+10];
    int dp[n+10];
    for (int i=1; i<=n; ++i) {
	cin >> arr[i];
	total[arr[i]]++;
    }
    int l=d;
    int cnt=((arr[0]==d)?1:0);
    dp[d]=cnt;
    num[d]=d;
    for (int i=d; i<=arr[n]; ++i) {
	num[i+num[d]-1]=num[d]-1; max[i+num[d]-1]=MAX(max[i+num[d]-1], max[i]+total[i+num[d]-1]);
	num[i+num[d]]=num[d]; max[i+num[d]]=MAX(max[i+num[d]], max[i]+total[i+num[d]]);
	num[i+num[d]+1]=num[d]+1; max[i+num[d]+1]=MAX(max[i+num[d]+1], max[i]+total[i+num[d]+1]);
    }
