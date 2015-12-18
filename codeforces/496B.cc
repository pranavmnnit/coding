#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
    int n,i,j;
    set<string> S;
    string str;
    cin >> n;
    cin >> str;
    S.insert(str);
    for (i=0; i<n; ++i) {
	int x=str[i]?(10-str[i]+'0'):0;
	string str2; stringstream st;
	for (j=0; j<n; ++j) {
	    st << (str[j]-'0'+x)%10;
	}
	str2=st.str();
	string str3=str2.substr(i,n-i)+str2.substr(0,i);
	S.insert(str3);
    }
    cout << *(S.begin());
    cout << endl;
    return 0;
}
