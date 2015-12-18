#include <iostream>
#include <map>
#include <cstdlib>
using namespace std;

inline long long msb(long long x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    x -= (x >> 1);
    return x;
}

inline long long fun(long long x) {
    long n=0;
    while(x>>=1) {
	n++;
    }
    return n;
}

int main() {
    bool rootBlack = true;
    map<long, bool> path;
    int Q;
    string str;
    long long x, y, lca;
    cin >> Q;
    while (Q--) {
	//long norl=0,nor1=0,nor2=0;
	path.clear();
	cin >> str;
	if (!str.compare("Qi")) {
	    rootBlack = !rootBlack;
	} else {
	    lca = 1;
	    cin >> x >> y;
	    long long x2=x, y2=y, lca2=lca;
	    long long h1, h2, hl = 0;
	    while (x || y) {
		if (x==1 && y==1) { lca = 1; break; }
		if (x == y) { lca = x; break; }
		if (x && path[x] == true) { lca = x; break; }
		if (y && path[y] == true) { lca = y; break; }
		if (x) path[x] = true;
		if (y) path[y] = true;
		x /= 2; y /= 2;
	    }
	    //cout << "lca= " << lca << endl;
	    x2 = msb(x2); y2 = msb(y2); lca2 = msb(lca);
	    //cout << "x= " << x2 << ", y= " << y2 << endl;
	    h1 = fun(x2); h2 = fun(y2); hl = fun(lca2);
	    //cout << "h1= " << h1 << ", h2= " << h2 << ", hl= " << hl << endl;
	    long non = abs(h1-hl) + abs(hl-h2) + 1;
	    //cout << "non= " << non << endl;
	    if (!str.compare("Qr")) {
		if (non == 1) {
		    if (rootBlack) {
			if (h1%2==0) {
			    cout << 0 << endl;
			} else {
			    cout << 1 << endl;
			}
		    } else {
			if (h1%2==0) {
			    cout << 1 << endl;
			} else {
			    cout << 0 << endl;
			}
		    }
		} else if (non%2==0) {
		    cout << non/2 << endl;
		} else if (rootBlack) {
		    if (h1%2==0) {
			cout << non/2 << endl;
		    } else {
			cout << (non+1)/2 << endl;
		    }
		} else {
		    if (h1%2==0) {
			cout << (non+1)/2 << endl;
		    } else {
			cout << non/2 << endl;
		    }
		}
	    } else if (!str.compare("Qb")) {
		if (non == 1) {
		    if (rootBlack) {
			if (h1%2==0) {
			    cout << 1 << endl;
			} else {
			    cout << 0 << endl;
			}
		    } else {
			if (h1%2==0) {
			    cout << 0 << endl;
			} else {
			    cout << 1 << endl;
			}
		    }
		} else if (non%2==0) {
		    cout << non/2 << endl;
		} else if (!rootBlack) {
		    if (h1%2==0) {
			cout << non/2 << endl;
		    } else {
			cout << (non+1)/2 << endl;
		    }
		} else {
		    if (h1%2==0) {
			cout << (non+1)/2 << endl;
		    } else {
			cout << non/2 << endl;
		    }
		}
	    }
	}
    }
    return 0;
}



#if 0
	    if (!str.compare("Qr")) {
		if (non%2==0) {
		    cout << non/2 << endl;
		} else {
		    if (rootBlack) {
			norl =(hl%2!=0)?(hl+1)/2:hl/2;
			nor1 =(h1%2!=0)?(h1+1)/2:h1/2;
			nor2 =(h2%2!=0)?(h2+1)/2:h2/2;
		    } else {
			norl = (hl%2!=0)?hl/2:(hl+1)/2;
			nor1 = (h1%2!=0)?h1/2:(h1+1)/2;
			nor2 = (h2%2!=0)?h2/2:(h2+1)/2;
		    }
		    cout << nor1+nor2-2*norl << endl;
		}
	    } else if (!str.compare("Qb")) {
		if (non%2==0) {
		    cout << non/2 << endl;
		} else {
		    if (rootBlack) {
			norl = (hl%2!=0)?hl/2:(hl+1)/2;
			nor1 = (h1%2!=0)?h1/2:(h1+1)/2;
			nor2 = (h2%2!=0)?h2/2:(h2+1)/2;
		    } else {
			norl =(hl%2!=0)?(hl+1)/2:hl/2;
			nor1 =(h1%2!=0)?(h1+1)/2:h1/2;
			nor2 =(h2%2!=0)?(h2+1)/2:h2/2;
		    }
		    cout << nor1+nor2-2*norl << endl;
		}
	    }
	}
    }
    return 0;
}
#endif
