#include<iostream>
#include<algorithm>

using namespace std;

int n, ns[100'000], m, c(2'000'000'000), * lbp;

int main(void) {
	cin >> n >> m;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	for(int _n(0); _n < n; _n++) {
		lbp = lower_bound(ns + _n + 1, ns + n, ns[_n] + m);
		if(lbp != ns + n) c = min(c, (*lbp) - ns[_n]);
	}
	cout << c;
}