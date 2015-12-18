#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(vector<int>& v) {
    int sz=v.size();
    int sum=0;
    for (int i=0; i<sz; ++i) {
	int m=v[i];
	for (int j=i; j<sz; ++j) {
	    if (v[j]<m) m=v[j];
	    sum+=m;
	}
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i=1; i<=n; ++i) {
	v.push_back(i);
    }
    if (m==1) {
	for (int i=1; i<=n; ++i) {
	    cout << i << " ";
	}
	cout << endl;
	return 0;
    }
    int fp = f(v);
    int c = 1;
    while (next_permutation(v.begin(), v.end())) {
	if (f(v)==fp) ++c;
	if (c==m) {
	    for (int i=0; i<n; ++i) {
		cout << v[i] << " ";
	    }
	    cout << endl;
	    break;
	}
    }
    return 0;
}
