#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
    int n,m;
    string str[101];
    cin>> n >> m;
    for (int i=0; i<n; ++i) {
	cin >> str[i];
    }
    int prev=0;
    int i=1;
    while(prev<m) {
	i=1;
	while (i<=n-1 && (str[i-1][prev] <= str[i][prev])) ++i;
	if (i==n) break;
	else ++prev;
    }
    if (prev==m) {
	cout << m << endl;
	return 0;
    }
    int count=prev;
    int j;
    while (prev<m-1) {
	for (j=1;j<n;++j) { //row
	    if (str[j-1][prev]!=str[j][prev]) continue;
	    else {
		if (str[j][i-1]!=str[j][i]) {
		    break;
		}
	    }
	}
	if (j!=n) count++;
	else prev++;
    }
    cout << count << endl;
    return 0;
}
