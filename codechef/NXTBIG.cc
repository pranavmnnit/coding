#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n, flag;
    cin >> t;
    while (t--) {
	cin >> n;
	int arr[100010]={0};
	for (int i=0; i<n; ++i) {
	    cin >> arr[i];
	}
	for (int i=0; i<n; ++i) {
	    cout << arr[i];
	}
	cout << endl;
	flag=0;
	int i=n-2, j=n-1;
	while (i>=0 && arr[i]>=arr[i+1]) --i;
	if (i==-1) goto no;
	while (j>i && arr[j]<=arr[i]) ++j;
	arr[j]=arr[i]^arr[j]^(arr[i]=arr[j]);
	reverse(arr+i+1, arr+n);
	for (i=0; i<n; ++i) {
	    cout << arr[i];
	}
	goto ENDL;
no:
	cout << "NO NXTBIG";
ENDL:
	cout << endl;
    }
    return 0;
}
