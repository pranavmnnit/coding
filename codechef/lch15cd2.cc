#include <iostream>
using namespace std;

int main() {
    unsigned long long t, n, d;
    unsigned long long ans=0;
    cin >> t;
    while (t--) {
	ans=0;
	cin >> n >> d;
	if (1==n) {
	    while (--d) {
		ans+=(d*d);
	    }
	    cout << ans << endl;
	} else {
	    unsigned long long num1, num2, cur=0, curs=0;
	    while (--d) {
		num1=((n%2)==0?0:cur); num2=((n%2)==0?(cur^(cur+1)):cur+1); curs=n*cur;
		//cout << "num1= " << num1 << ", num2= " << num2 << endl;
		bool flag=1; ++cur;
		for (unsigned long long i=0; i<n; ++i) {
		    //cout << "now ans= " << ans << ", curs= " << curs << endl;
		    if (flag) {
			ans+=(num1*curs);
		    } else {
			ans+=(num2*curs);
		    }
		    ++curs; flag=!flag;
		}
		//cout << "after iter.., ans= " << ans << ", curs= " << curs << endl;
	    }
	    cout << ans << endl;
	}
    }
    return 0;
}
