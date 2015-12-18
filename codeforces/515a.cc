#include<iostream>
#define abs(a) ((a)<0?(-(a)):(a))
using namespace	std;

int main(){
	long a,b,s;

	cin>>a>>b>>s;

	long long total = abs(a)+abs(b);
	total = s-total;
	if(total<0) {
	    cout << "No" << endl;
	    return 0;
	}
	if(total%2==0) {
	    cout << "Yes\n";
	} else {
	    cout << "No\n";
	}
return 0;
}
