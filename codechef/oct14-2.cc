#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;

int main() {
    int T, N;
    int arr[1000010];
    long cost;
    stack< pair<int, int> > st;
    queue< pair<int, int> > q;
    cin >> T;
    while (T--) {
	cost = 0;
	cin >> N;
	queue< pair<int, int> > eQ;
	swap(q, eQ);
	stack< pair<int, int> > eS;
	swap(st, eS);
	for (int i=0; i<N; ++i) {
	    cin >> arr[i];
	}
	for (int i=0; i<N; ++i) {
	    if (arr[i] > 0) {
		st.push(make_pair(i, arr[i]));
	    } else if (arr[i] < 0) {
		q.push(make_pair(i, -arr[i]));
	    }
	    while (!q.empty() && !st.empty()) {
		pair<int, int> s = st.top();
		pair<int, int> pa = q.front();
		st.pop(); q.pop();
		if (pa.second == s.second) {
		    cost += (abs(pa.first-s.first)*pa.second);
		    cout << "equal, cost= " << cost << endl;
		} else if (pa.second < s.second) {
		    cost += (abs(pa.first-s.first)*pa.second);
		    cout << "by stack more, cost= " << cost << endl;
		    st.push(make_pair(s.first, s.second - pa.second));
		} else {
		    cost += (abs(pa.first-s.first)*s.second);
		    cout << "by stack less, cost= " << cost << endl;
		    q.push(make_pair(pa.first, pa.second - s.second));
		}
	    }
	}
	cout << cost << endl;
    }
    return 0;
}
