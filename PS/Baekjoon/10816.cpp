#include<iostream>
#include<algorithm>

using namespace std;

int upper_bound(const int* _ns, const int _n, const int _t) {
	int s(0), e(_n), m;
	while (s != e) {
		m = (s + e) / 2;
		if (_ns[m] <= _t)
			s = m + 1;
		else e = m;
	}
	return e;
}

int lower_bound(const int* _ns, const int _n, const int _t) {
	int s(0), e(_n), m;
	while (s != e) {
		m = (s + e) / 2;
		if (_ns[m] >= _t)
			e = m;
		else s = m + 1;
	}
	return e;
}

int n, m, ns[500000], t;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int _n(0); _n < n; _n++) 
		cin >> ns[_n];
	sort(ns, ns + n);
	cin >> m;
	for (int _m(0); _m < m; _m++) {
		cin >> t;
		cout << upper_bound(ns, n, t) - lower_bound(ns, n, t) << ' ';
	}
}