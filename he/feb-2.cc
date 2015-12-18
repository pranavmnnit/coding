#include <iostream>
#define max(a, b) ((a)>(b)?(a):(b))
using namespace std;

int lcs[5001][5001];

int main() {
    string s1, s2, S1, S2;
    cin >> S1 >> S2;
    int sz1=S1.size();
    for (int i=0; i<sz1; ++i) {
	if (S1[i]!='a' && S1[i]!='e' && S1[i]!='i' && S1[i]!='o' && S1[i]!='u') s1+=S1[i];
    }
    int sz2=S2.size();
    for (int i=0; i<sz2; ++i) {
	if (S2[i]!='a' && S2[i]!='e' && S2[i]!='i' && S2[i]!='o' && S2[i]!='u') s2+=S2[i];
    }
    sz1=s1.size(); sz2=s2.size();
    for (int i=1; i<=sz1; ++i) {
	for (int j=1; j<=sz2; ++j) {
	    if (s1[i-1]==s2[j-1]) {
		lcs[i][j]=lcs[i-1][j-1]+1;
	    } else {
		lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
	    }
	}
    }
    cout << lcs[sz1][sz2] << endl;
    return 0;
}
