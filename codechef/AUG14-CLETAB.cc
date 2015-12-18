#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define tr(object, it) \
    for(typeof(object.begin()) it = object.begin(); it != object.end(); ++it)
using namespace std;

int main() {
    unsigned T, N, M, A, cost=0;
    set<unsigned> table;
    vector<unsigned> arr;
    vector<unsigned>::iterator vitr;
    cin >> T;
    while (T--) {
	arr.erase(arr.begin(), arr.end());
	table.erase(table.begin(), table.end());
	cin >> N >> M;
	for (unsigned i = 0; i < M; ++i) {
	    cin >> A;
	    arr.push_back(A);
	}
	unsigned j=0;
	while ((table.size() < N) && (j<M)) {
	    table.insert(arr[j]);
	    ++j;
	}
	cost=table.size();
	//tr (table, it) {
	//    cout << "Initial: " << *it << endl;
	//}
	for (; j<M; ++j) {
	    //cout << "will find place for " << arr[j] << endl;
	    if (table.find(arr[j]) != table.end()) {
		cout << arr[j] << "already has table " << endl;
	        continue;
	    }
	    tr (table, it) {
		//cout << "searching for " << *it << endl;
		vitr = std::find(arr.begin()+j+1, arr.end(), *it);
		if (vitr != arr.end()) {
		    cout << "will come again " << *vitr << endl;
		} else {
		    cout << "Removing from table " << *it << endl;
		    table.erase(*it);
		    break;
		}
	    }
	    if (vitr != arr.end()) {
		cout << "No space, Removing from table, " << *(table.begin()) << endl;
		table.erase(table.begin());
	    }
	    cout << "Giving table to: " << arr[j] << endl;
	    table.insert(arr[j]);
	    ++cost;
	    //cout << "cost=" << cost << endl;
	}
	cout << cost << endl;
    }
    return 0;
}
