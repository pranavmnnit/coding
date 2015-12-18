#include <iostream>
#include <cstring>
#include <vector>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define tr(obj, it) for (typeof(obj.begin()) it = obj.begin(); it != obj.end(); ++it)
#define ll long long
using namespace std;

char str[100010];
char str2[100010];

int main() {
    int t, type;
    scanf("%d", &t);
    while (t--) {
	int cntB = 0, cntG = 0;
	ll ans, ans2;
	vector<int> dist;
	scanf("%d", &type);
	scanf("%s", str);
	str2[0] = '\0';
	int sz = strlen(str);
	for (int i = 0; i < sz; ++i) {
	    if (str[i] == 'B') ++cntB;
	    else ++cntG;
	}
	if (cntB - cntG > 1 || cntG - cntB > 1) {
	    printf("-1\n");
	    continue;
	}
	int reqG = 0, reqB = 0;
	switch (type) {
	    case 0:
		//BGBG..
		for (int i = 0; i < sz; i += 2) {
		    if (str[i] == 'G') ++reqB;
		}
		for (int i = 1; i < sz; i += 2) {
		    if (str[i] == 'B') ++reqB;
		}
		//GBGB..
		for (int i = 0; i < sz; i += 2) {
		    if (str[i] == 'B') ++reqG;
		}
		for (int i = 1; i < sz; i += 2) {
		    if (str[i] == 'G') ++reqG;
		}

		if (cntB > cntG) {
		    printf("%d\n", reqB/2);
		} else if (cntG > cntB){
		    printf("%d\n", reqG/2);
		} else {
		    printf("%d\n", MIN(reqG, reqB)/2);
		}
		break;
	    case 1:
		ans = 0, ans2 = 0;
		strncpy(str2, str, sz);
		//BGBG..
		for (int i = 0, j = 0; i < sz; ++i) {
		    if (i%2 == 0 && str2[i] != 'B') {
			j = i + 1;
			while (str2[j] == 'G') ++j;
			str2[j] = str2[i] ^ str2[j] ^ (str2[i] = str2[j]);
			//printf("pushing1: %d %d\n", i, j);
			dist.push_back(j - i);
		    } else if (i%2 != 0 && str2[i] != 'G') {
			j = i + 1;
			while (str2[j] == 'B') ++j;
			str2[j] = str2[i] ^ str2[j] ^ (str2[i] = str2[j]);
			//printf("pushing2: %d %d\n", i, j);
			dist.push_back(j - i);
		    }
		}
		tr (dist, it) {
		    ans += *it;
		}
		dist.clear();

		//GBGB..
		for (int i = 0, j = 0; i < sz; ++i) {
		    if (i%2 == 0 && str[i] != 'G') {
			j = i + 1;
			while (str[j] == 'B') ++j;
			str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			dist.push_back(j - i);
			//printf("pushing3: %d %d\n", i, j);
		    } else if (i%2 != 0 && str[i] != 'B') {
			j = i + 1;
			while (str[j] == 'G') ++j;
			str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			//printf("pushing4: %d %d\n", i, j);
			dist.push_back(j - i);
		    }
		}
		tr (dist, it) {
		    ans2 += *it;
		}
		if (cntB > cntG) {
		    printf("%lld\n", ans);
		} else if (cntG > cntB) {
		    printf("%lld\n", ans2);
		} else {
		    printf("%lld\n", MIN(ans, ans2));
		}
		break;
	    case 2:
		ans = 0, ans2 = 0;
		if (cntB > cntG) {
		    //BGBG..
		    for (int i = 0, j = 0; i < sz; ++i) {
			if (i%2 == 0 && str[i] != 'B') {
			    j = i + 1;
			    while (str[j] == 'G') ++j;
			    str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			    //printf("pushing1: %d %d\n", i, j);
			    dist.push_back(j - i);
			} else if (i%2 != 0 && str[i] != 'G') {
			    j = i + 1;
			    while (str[j] == 'B') ++j;
			    str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			    //printf("pushing2: %d %d\n", i, j);
			    dist.push_back(j - i);
			}
		    }
		    tr (dist, it) {
			ans += (1LL * (*it) * (*it));
		    }
		    printf("%lld\n", ans);
		} else if (cntG > cntB) {
		    //GBGB..
		    for (int i = 0, j = 0; i < sz; ++i) {
			if (i%2 == 0 && str[i] != 'G') {
			    j = i + 1;
			    while (str[j] == 'B') ++j;
			    str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			    dist.push_back(j - i);
			    //printf("pushing3: %d %d\n", i, j);
			} else if (i%2 != 0 && str[i] != 'B') {
			    j = i + 1;
			    while (str[j] == 'G') ++j;
			    str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			    //printf("pushing4: %d %d\n", i, j);
			    dist.push_back(j - i);
			}
		    }
		    tr (dist, it) {
			ans2 += (1LL * (*it) * (*it));
		    }
		    printf("%lld\n", ans2);
		} else {
		    ans = 0, ans2 = 0;
		    strncpy(str2, str, sz);
		    //BGBG..
		    for (int i = 0, j = 0; i < sz; ++i) {
			if (i%2 == 0 && str2[i] != 'B') {
			    j = i + 1;
			    while (str2[j] == 'G') ++j;
			    str2[j] = str2[i] ^ str2[j] ^ (str2[i] = str2[j]);
			    //printf("pushing1: %d %d\n", i, j);
			    dist.push_back(j - i);
			} else if (i%2 != 0 && str2[i] != 'G') {
			    j = i + 1;
			    while (str2[j] == 'B') ++j;
			    str2[j] = str2[i] ^ str2[j] ^ (str2[i] = str2[j]);
			    //printf("pushing2: %d %d\n", i, j);
			    dist.push_back(j - i);
			}
		    }
		    tr (dist, it) {
			ans += (1LL * (*it) * (*it));
		    }
		    dist.clear();

		    //GBGB..
		    for (int i = 0, j = 0; i < sz; ++i) {
			if (i%2 == 0 && str[i] != 'G') {
			    j = i + 1;
			    while (str[j] == 'B') ++j;
			    str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			    dist.push_back(j - i);
			    //printf("pushing3: %d %d\n", i, j);
			} else if (i%2 != 0 && str[i] != 'B') {
			    j = i + 1;
			    while (str[j] == 'G') ++j;
			    str[j] = str[i] ^ str[j] ^ (str[i] = str[j]);
			    //printf("pushing4: %d %d\n", i, j);
			    dist.push_back(j - i);
			}
		    }
		    tr (dist, it) {
			ans2 += (1LL * (*it) * (*it));
		    }
		    printf("%lld\n", MIN(ans, ans2));
		}
	}
    }
    return 0;
}
