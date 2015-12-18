#include <iostream>
#define ull unsigned long long
using namespace std;

int DO(ull curH, ull h, ull node, ull reqd, int left, ull& cnt) {
    int ret=0;
    if (curH==h && node==reqd) return 0;
    if (curH==h && node!=reqd) return -1;
    if (left==1) {
	++cnt;
	ret=DO(curH+1, h, node*2+1, reqd, -left, cnt);
	if (!ret) return 0;
	++cnt;
	ret=DO(curH+1, h, node*2+2, reqd, left, cnt);
	return ret;
    } else {
	++cnt;
	ret=DO(curH+1, h, node*2+2, reqd, -left, cnt);
	if (!ret) return 0;
	++cnt;
	ret=DO(curH+1, h, node*2+1, reqd, left, cnt);
	return ret;
    }
}

int main() {
    ull h, n;
    cin >> h >> n;
    ull cnt=0;
    int A=DO(0, h, 0, (1<<h)-2+n, 1, cnt);
    cout << cnt << endl;
    return 0;
}
