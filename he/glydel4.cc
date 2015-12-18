#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int BASE=150;

int main() {
    int N;
    unsigned int m=0;
    char names[1000010][6];
    char names2[1000010][6];
    cin >> N;
    for (int i=0; i<N; ++i) {
	scanf("%s", names[i]);
	if (strlen(names[i]) > m) {
	    m = strlen(names[i]);
	}
    }
    unsigned int exp=1;
    while (exp<=m) {
	int bucket[BASE] = {0};

	for (int i=0; i<N; ++i) {
	    if (strlen(names[i])-exp>=0) {
		bucket[names[i][strlen(names[i])-exp]-'a']++;
	    }
	}
	for (int i=1; i<26; ++i) {
	    bucket[i] += bucket[i-1];
	}
	for (int i=N-1; i>=0; --i) {
	    --bucket[names[i][strlen(names[i])-exp]-'a'];
	    strcpy(names2[bucket[names[i][strlen(names[i])-exp]-'a']], names[i]);
	}
	//for (int i=0; i<N; ++i) {
	//    cout << "old= " << names[i] << ", new= " << names2[i] << endl;
	//}
	//cout << "............." << endl;
	for (int i=0; i<N; ++i) {
	    strcpy(names[i], names2[i]);
	}
	++exp;
    }
    vector<string> vec(names, names+N);
    vector<string>::iterator it = vec.begin();
    vector<string>::iterator it2 = unique(vec.begin(), vec.end());
    cout << distance(it, it2) << endl;
    for (;it != it2; ++it) {
	cout << *it << endl;
    }
    return 0;
}
