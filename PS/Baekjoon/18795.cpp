#include<iostream>
#include<numeric>

using namespace std;

typedef long long int lli;

lli n, m, ns[500'000], ms[500'000];

int main(void) {
	cin >> n >> m;
	for (lli _n(0); _n < n; _n++) 
		cin >> ns[_n];
	for (lli _m(0); _m < m; _m++) 
		cin >> ms[_m];
	cout << accumulate(ns, ns + n, 0LL) + accumulate(ms, ms + m, 0LL);
}