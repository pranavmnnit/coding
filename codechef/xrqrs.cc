#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define tr(obj, it) for(typeof((obj).begin()) it = (obj).begin(); it != (obj).end(); ++it)
using namespace std;

class trie {
    private:
	int num; //0, 1
	vector<int> idx;
	trie* left;
	trie* right;
    public:
	trie() : left(NULL), right(NULL), num(-1) { }
	trie(int n) : left(NULL), right(NULL), num(n) { }
	void addNode(string& str, int pos, int sz, int idx);
	void delNode(int idx, int& status);
	void print();
	bool contains(int L, int R);
	bool contains(int idx);
	void maxNum(int L, int R, string& str, int pos, int sz, string& ans); // L .. R s.t. X^Y is max.
	int lessThan(int L, int R, int X); // L .. R, count of num less than X
	int kthSmall(int L, int R); // L .. R, kth smallest number
};

string tostr(int n) { // returns binary representation of the number
    string str;
    while (n) {
	str += ((n & 1) ? "1" : "0");
	n >>= 1;
    }
    reverse(str.begin(), str.end());
    return str;
}

int tonum(string str) {
    int ans = 0, sz = str.size();
    for (int i = 0; i < sz; ++i) {
	if (str[sz - i - 1] == '1') ans += (1 << i);
    }
    return ans;
}

bool
trie::contains(int L, int R) {
    if (*(this->idx.begin()) > R || *(this->idx.end() - 1) < L) return false;
    return true;
}

bool
trie::contains(int id) {
    if ((id  >= *(this->idx.begin())) && (id <= *(this->idx.end() - 1))) return true;
    return false;
}

void
trie::print() {
    if (!this) return;
    if (this->left) this->left->print();
    if (this->right) this->right->print();
    cout << "indexes = "; tr (this->idx, it) cout << *it << ", ";
    cout << " | num = " << num << endl;
}

void
trie::maxNum(int L, int R, string& req, int pos, int sz, string& ans) {
    if (pos == sz) return;
    if (req[pos] == '0') {
	if (this->right && this->right->contains(L, R)) {
	    ans += '1';
	    this->right->maxNum(L, R, req, pos + 1, sz, ans);
	} else if (this->left && this->left->contains(L, R)) {
	    ans += '0';
	    this->left->maxNum(L, R, req, pos + 1, sz, ans);
	}
    } else {
	if (this->left && this->left->contains(L, R)) {
	    ans += '0';
	    this->left->maxNum(L, R, req, pos + 1, sz, ans);
	} else if (this->right && this->right->contains(L, R)) {
	    ans += '1';
	    this->right->maxNum(L, R, req, pos + 1, sz, ans);
	}
    }
}

void
trie::addNode(string& str, int pos, int sz, int idx) {
    this->idx.push_back(idx);
    if (pos == sz) {
	return;
    }
    if (str[pos] == '1') {
	if (this->right == NULL) {
	    trie *node = new trie(str[pos] - '0');
	    this->right = node;
	}
	this->right->addNode(str, pos + 1, sz, idx);
    } else {
	if (this->left == NULL) {
	    trie *node = new trie(str[pos] - '0');
	    this->left = node;
	}
	this->left->addNode(str, pos + 1, sz, idx);
    }
}

void
trie::delNode(int id, int& status) {
    if (this->left)  {
	this->left->delNode(id, status);
    }
    if (status == 1) {
	delete(this->left);
	this->left = NULL; status = 0;
    }
    if (this->right) {
	this->right->delNode(id, status);
    }
    if (status == 1) {
	delete(this->right);
	this->right = NULL; status = 0;
    }
    if (this->contains(id)) {
	this->idx.erase(remove(this->idx.begin(), this->idx.end(), id), this->idx.end());
	if (this->idx.size() == 0) status = 1;
    } else status = 0;
}

int main() {
    int M, mall = 0;
    int end, L, R, T, X, K;
    end=0;
    trie Trie;
    scanf("%d", &M);
    while (M--) {
	scanf("%d", &T);
	if (T == 0) {
	    scanf("%d", &X);
	    if (X > mall) mall = X;
	    string s = tostr(X); ++end;
	    Trie.addNode(s, 0, s.size(), end);
	    Trie.print();
	} else if (T == 1) {
	    scanf("%d %d %d", &L, &R, &X);
	    string s, ans;
	    for (int i = (int)log2(mall) - (int)log2(X) ; i > 0 ; --i) {
		s += '0';
	    }
	    s += tostr(X);
	    Trie.maxNum(L, R, s, 0, s.size(), ans);
	    cout << tonum(ans) << endl;
	} else if (T == 2) {
	    scanf("%d", &K);
	    for (int i = end; i > (end - K); --i) {
		int status = 0;
		Trie.delNode(i, status);
	    }
	    end -= K;
	    Trie.print();
	} else if (T == 3) {
	    scanf("%d %d %d", &L, &R, &X);
	    int cnt=0;
	    printf("%d\n", cnt);
	} else if (T == 4) {
	    scanf("%d %d %d", &L, &R, &K);
	}
    }
    return 0;
}
