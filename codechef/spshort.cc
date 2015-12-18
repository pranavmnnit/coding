#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t, n, m, a, b, cost;
    scanf("%lld", &t);
    while (t--) {
	scanf("%lld %lld", &n, &m);
	while (m--) {
	    scanf("%lld %lld %lld", &a, &b, &cost);
