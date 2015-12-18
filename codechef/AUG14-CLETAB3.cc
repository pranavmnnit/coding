#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define tr(object, it) \
    for(typeof(object.begin()) it = object.begin(); it != object.end(); ++it)
using namespace std;

int main() {
    unsigned T, N, M, A, cost=0, j=0;
    set<unsigned> table;
    set< pair<unsigned, unsigned> > rem;
    vector<unsigned> arr;
    vector<unsigned>::iterator vitr, vitr2;
    cin >> T;
    while (T--) {
	cost = 0; j = 0;
	rem.erase(rem.begin(), rem.end());
	arr.erase(arr.begin(), arr.end());
	table.erase(table.begin(), table.end());
	cin >> N >> M;
	for (unsigned i = 0; i < M; ++i) {
	    cin >> A;
	    arr.push_back(A);
	}
	while ((table.size() < N) && (j < M)) {
	    table.insert(arr[j]);
	    ++j;
	}
	cost = table.size();
	for (; j<M; ++j) {
	    if (table.find(arr[j]) != table.end()) {
		continue;
	    }
	    tr (table, it) {
		vitr = std::find(arr.begin()+j, arr.end(), *it);
		if (vitr == arr.end()) {
		    table.erase(*it);
		    break;
		} else {
		    rem.insert(make_pair((vitr-arr.begin())-j, *it));
		}
	    }
	    if (vitr != arr.end()) {
		table.erase((*rem.rbegin()).second);
	    }
	    rem.erase(rem.begin(), rem.end());
	    table.insert(arr[j]);
	    ++cost;
	}
	cout << cost << endl;
    }
    return 0;
}
