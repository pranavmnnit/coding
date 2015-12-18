#include <iostream>
#include <set>
#include <vector>
#include <map>
#define MA 1000000001
using namespace std;

int main() {
    int N, M;
    int age;
    int w_age=-1, w_no=-1;

    cin >> N >> M;
    map<long, int> won; //age->won
    for (int i=0; i<N; ++i) {
        cin >> age;
        won[age]++;
        if (won[age]>w_no || (won[age]>=w_no && age>w_age)) {
            w_age=age;
            w_no=won[age];
        }
        cout << w_age << " " << w_no << endl;
    }
    return 0;
}
