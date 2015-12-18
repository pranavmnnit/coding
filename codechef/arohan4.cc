#include <iostream>
#include <cstring>
#define NUM(ch) ((ch-'0'))
using namespace std;

int main() {
    int ans[210];
    int T;
    string str;
    cin >> T;
    while (T--) {
	memset(ans, 0, 210*sizeof(int));
	cin >> str;
	int sz=str.find_first_of("+-");
	string op1(str, 0, sz);
	string op2(str, sz+1, str.size()-sz);
	int s1= op1.size(); int s2=op2.size();
	if (str[sz]=='+') {
	    string op3;
	    if (s1<s2) {
		op3=op1; op1=op2; op2=op3;
		int s3=s1; s1=s2; s2=s3;
	    }
	    int idx=(s1>s2?s1:s2); int idx2=idx;
	    int carry=0;
	    while (s1 && s2) {
		ans[idx]=(carry+NUM(op1[s1-1])+NUM(op2[s2-1]))%10;
		carry=(NUM(op1[s1-1])+NUM(op2[s2-1])+carry)/10;
		//cout << "placed at idx= " << idx << ", val= " << ans[idx] << endl;
		--s1; --s2; --idx;
	    }
	    while (idx) {
		ans[idx]=(carry+NUM(op1[s1-1]))%10;
		//cout << "placed at idx= " << idx << ", val= " << ans[idx] << endl;
		carry=(carry+NUM(op1[s1-1]))/10;
		--idx; --s1;
	    }
	    if (carry) cout << carry;
	    for (int i=1; i<=idx2; ++i) {
		cout << ans[i];
	    }
	    cout << endl;
	} else {
	    bool sign=0; //+
	    if (!op1.compare(op2)) { cout << 0 << endl; continue; }
	    if (s1==s2) {
		if (op1.compare(op2)<0) { string t=op1; op1=op2; op2=t; sign=1; int s3=s1; s1=s2; s2=s3; }
	    } else if (s1<s2) {
		string t=op1; op1=op2; op2=t;
		int s3=s1; s1=s2; s2=s3;
		sign=1; //-
	    }
	    int idx=(s1>s2?s1:s2); int idx2=idx;
	    int borrow=0;
	    while (s1 && s2) {
		ans[idx]=(((10*borrow)+NUM(op1[s1-1]))-NUM(op2[s2-1])+10)%10;
		if(NUM(op1[s1-1]) < NUM(op2[s2-1])) borrow=1;
		else borrow=0;
		//cout << "placed at idx= " << idx << ", val= " << ans[idx] << endl;
		--s1; --s2; --idx;
	    }
	    while (idx) {
		//cout << "borrow= " << borrow << endl;
		ans[idx]=(((10*borrow)+NUM(op1[s1-1]))+10)%10;
		if (borrow && !NUM(op1[s1-1])) borrow=1;
		else borrow=0;
		//cout << "placed at idx= " << idx << ", val= " << ans[idx] << endl;
		--idx; --s1;
	    }
	    int i=1;
	    while (!ans[i] && (i<=idx2)) ++i;
	    if (i>idx2) { cout << 0 << endl; continue; }
	    if (sign) cout << "-";
	    for (; i<=idx2; ++i) {
		cout << ans[i];
	    }
	    cout << endl;
	}
    }
    return 0;
}
