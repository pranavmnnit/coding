#include <iostream>
#include <sstream>
using namespace std;

char arr[][2] = {
    {'B', 'E'}, {'A','C'}, {'D', 'B'}, {'E', 'C'}, {'D', 'A'}
};
char arr2[][2] = {
    {'C', 'D'}, {'D', 'E'}, {'E', 'A'}, {'A', 'B'}, {'B', 'C'}
};

string func(string str, bool outer) {
    stringstream s;
    long ans=0;
    long a=(str[0]-'A')+(outer?0:5);
    s << a;
    long sz=str.size();
    for (long i=1; i<sz; ++i) {
	if (outer) {
	    if (str[i-1] == str[i]) {
		outer = false;
		ans=(str[i]-'A'+5);
		s << ans;
	    } else {
		if (arr[str[i-1]-'A'][0]==str[i] || arr[str[i-1]-'A'][1]==str[i]) {
		    ans=(str[i]-'A');
		    s << ans;
		} else {
		    return "-1";
		}
	    }
	} else {
	    if (str[i-1]==str[i]) {
		outer=true;
		ans=(str[i]-'A');
		s << ans;
	    } else {
		if (arr2[str[i-1]-'A'][0]==str[i] || arr2[str[i-1]-'A'][1]==str[i]) {
		    ans=(str[i]-'A'+5);
		    s << ans;
		} else {
		    return "-1";
		}
	    }
	}
    }
    return s.str();
}

int main() {
    short T;
    string ans;
    string str;
    cin >> T;
    while (T--) {
	cin >> str;
	ans = func(str, true);
	if (ans.compare("-1")) {
	    cout << ans << endl;
	    continue;
	}
	cout << func(str, false) << endl;
    }
    return 0;
}
