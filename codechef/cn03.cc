#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> vec;

int isPossible(long long C, long long dist) {
    long long d=0, cnt=1;
    vector<long long>::iterator vitr=vec.begin();
    ++vitr;
    for (; vitr!=vec.end(); ++vitr) {
	d+=(*vitr-*(vitr-1));
	if (d<dist) continue;
	else {
	    d=0;
	    ++cnt;
	    if (cnt==C) return 1;
	}
    }
    return 0;
}

int main() {
    long long N, a, C, ans=-1;
    cin >> N >> C;
    for (long long i=0; i<N; ++i) {
	cin >> a;
	vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    long long min=0;
    long long max=2*(vec.back() - *(vec.begin()));
    long long mid;
    while (max>=min) {
	mid=(min+max)/2;
	if (isPossible(C, mid)) {
	    ans=(mid>ans?mid:ans);
	    min=mid+1;
	} else {
	    max=mid-1;
	}
    }
    cout << ans << endl;
    return 0;
}
