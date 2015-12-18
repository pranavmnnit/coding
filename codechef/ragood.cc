#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define tr(obj, it) for(typeof(obj.begin()) it = obj.begin(); it != obj.end(); ++it)
using namespace std;

int start[100010], end[100010];

vector< pair<int, int> > times;

bool func(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first < p2.first) return true;
    if (p2.first < p1.first) return false;
    return (p1.second > p2.second);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
	int n;
	cin >> n;
	times.clear();
	for (int i = 0; i < n; ++i) {
	    cin >> start[i];
	}
	for (int i = 0; i < n; ++i) {
	    cin >> end[i];
	}
	for (int i = 0; i < n; ++i) {
	    times.push_back(make_pair(end[i], start[i]));
	}
	sort(times.begin(), times.end(), func);
	int cnt = 1, last = times.begin()->first;
	tr (times, it) {
	    if (it->first == last)  continue;
	    if (it->second >= last) {
		++cnt; last = it->first;
	    }
	}
	cout << cnt << endl;
    }
    return 0;
}
