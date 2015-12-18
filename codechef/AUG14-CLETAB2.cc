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
    vector<unsigned> arr;
    vector<unsigned>::iterator vitr;
    cin >> T;
    while (T--) {
	cost = 0;
	arr.erase(arr.begin(), arr.end());
	table.erase(table.begin(), table.end());
	cin >> N >> M;
	for (unsigned i = 0; i < M; ++i) {
	    cin >> A;
	    arr.push_back(A);
	}
	for (j=0; j<M; ++j) {
	    if (table.find(arr[j]) != table.end()) {
		cout << "already in table " << arr[j] << endl;
	        continue;
	    } else if (table.size() < N) {
		cout << "inserting in table " << arr[j] << endl;
		table.insert(arr[j]);
		++cost;
		continue;
	    }
	    tr (table, it) {
		vitr = std::find(arr.begin()+j, arr.end(), *it);
		if (vitr == arr.end()) {
		    cout << "removing from table " << arr[j] << endl;
		    table.erase(*it);
		    break;
		}
	    }
	    if (vitr != arr.end()) {
		cout << "removing from table " << *vitr << endl;
		table.erase(*vitr);
	    }
	    cout << "inserting in table " << arr[j] << endl;
	    table.insert(arr[j]);
	    ++cost;
	}
	cout << cost << endl;
    }
    return 0;
}
