#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#define for0n(i,n) for(int i=0;i<n;i++)
#define for1n(i,n) for(int i=1;i<n;i++)
#define forij(i,j) for(int k=i;k<j;k++)
using namespace std;

class sorter;
typedef multimap<int, pair<int,int>, sorter> MapT;

class sorter {
    public:
    bool operator() (const int& M1, const int& M2) {
        if (M1 > M2) return true;
        return false;
    }
};

int minim(int a, int b, int c) {
    int m = a;
    if (m > b) m = b;
    if (m > c) m = c;
    return m;
}

void clearLinks(map<int, int>& Link) {
    map<int, int>::iterator it;
    for (it = Link.begin(); it != Link.end(); it++) {
	it->second = 0;
    }
}
int main()
{
    int N, arr[100], Max = -1000, Max2 = -1000, moreNeeded;
    MapT Map;
    map<int, int> Link;
    map<int, int>::iterator LinkIt;
    MapT::iterator MapIt, MapIt2;
    cin >> N;

    for0n(i,N) {
        cin >> arr[i];
        if (Link.find(arr[i]) != Link.end()) {
            Link[arr[i]] += 2;
        } else {
            Link[arr[i]] = 2;
        }
    }
    if (N==3) {
        Max = minim((arr[0] ^ arr[1]), (arr[1] ^ arr[2]), (arr[2] ^ arr[0]));
        if (Max >= 1) {
            cout << (int)log2(Max);
        } else {
            cout << -1;
        }
        return 0;
    }
    for0n(i,N) {
        forij(i+1,N) {
            Map.insert(make_pair( (arr[i] ^ arr[k]), make_pair(arr[i], arr[k])) );
        }
    }

    for(MapIt = Map.begin(); MapIt != Map.end(); MapIt++) {
        cout << MapIt->first << " => ";
        cout << MapIt->second.first << ", ";
        cout << MapIt->second.second << endl;
    }

    int i = 1;
    for (MapIt = Map.begin(); MapIt != Map.end(); MapIt++, i++) {
	cout << "%%%%%% i=" << i << endl;
        if (i > ((N*(N-1)/2) - N)) {
            cout << "all done.. breaking..\n";
            break; // all done
        }
        if (MapIt->first <= Max) {
	    cout << "Can't get better, i=" << i << endl;
            break;
        }
        Max2 = MapIt->first;
	for0n(h,N) {
	    if (Link.find(arr[h]) != Link.end()) {
		Link[arr[h]] += 2;
	    } else {
		Link[arr[h]] = 2;
	    }
	}
        moreNeeded = N-1;
        cout << "Real Max=" << Max << endl;
        Link[MapIt->second.first]--;
        Link[MapIt->second.second]--;
        cout << "1. Link " << MapIt->second.first << ", " << MapIt->second.second << endl;
	MapIt2 = MapIt;
        for (++MapIt2; MapIt2 != Map.end(); MapIt2++) {
                //cout << "2.. Link " << MapIt2->second.first << ", " << MapIt2->second.second << endl;
                if ((Link[MapIt2->second.first]) && (Link[MapIt2->second.second])) {
                    Link[MapIt2->second.first]--;
                    Link[MapIt2->second.second]--;
                    cout << "2. Link " << MapIt2->second.first << ", " << MapIt2->second.second << endl;
                    Max2 = ((MapIt2->first) < Max2 ? MapIt2->first : Max2 ); // minimise the max!
                    cout <<"Intermed Max = " << Max2 << endl;
                    if (--moreNeeded == 0) {
                        Max = (Max2 > Max ? Max2 : Max);
                        cout << "no more needed." << endl ;
                        cout << "Real max=" << Max << endl;
                        break;
                    }
                } else {
                    cout << "3. Link " << MapIt2->second.first << ", " << MapIt2->second.second << endl;
                    cout << "Link value:" << Link[MapIt2->second.first] << ",," << Link[MapIt2->second.second] << endl;
                }
        }
	clearLinks(Link);
    }
    if (Max >= 1) {
        cout << (int)log2(Max);
    } else {
        cout << -1 << endl;
    }
    return 0;
}
