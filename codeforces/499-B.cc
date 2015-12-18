#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
    int N, M;
    string a, b;
    stringstream S;
    map<string,string> Map;
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
	cin >> a >> b;
	if (b.size() < a.size()) {
	    Map.insert(make_pair(a, b));
	} else {
	    Map.insert(make_pair(a, a));
	}
    }
    for (int i=0; i<N-1; ++i) {
	cin >> a;
	S << Map[a] << " ";
    }
    cin >> a;
    S << Map[a];
    cout << S.str() << endl;
    return 0;
}
