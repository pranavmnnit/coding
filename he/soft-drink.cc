#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q, n1, n2, n3;
    vector<int> s;
    cin >> Q;
    while (Q--) {
	s.clear();
	cin >> n1 >> n2 >> n3;
	s.push_back(n1); s.push_back(n2); s.push_back(n3);
	sort(s.begin(), s.end());
	int no3 = s[0];
	int no2 = s[1];
	int no1 = s[2];
	no1 -= no2; no2 -= no3;
	if (no3%2 == 0) no3=0; else no3=3;
	if (no2%2 == 0) no2=0; else no2=2;
	if (no1%2 == 0) no1=0; else no1=1;
	if ((no1^no2^no3) != 0) {
	    cout << "Ashima" << endl;
	} else {
	    cout << "Aishwarya" << endl;
	}
    }
    return 0;
}
