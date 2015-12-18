#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    int B[1001];
    string A;
    scanf("%d", &T);
    while (T--) {
	cin >> A;
	cin >> N;
	for (int i=0; i<N; ++i) {
	    cin >> B[i];
	}
	sort(A.begin(), A.end());
	cout << A << endl;
    }
    return 0;
}
