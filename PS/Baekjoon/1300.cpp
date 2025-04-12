#include<iostream>

using namespace std;

long long int n, k;

long long int gc(const long long int& _i) {
	long long int s(0);
	for (long long int _n(1); _n < n + 1 && _i / _n; _n++)
		s += min(_i / _n - (_i % _n ? 0 : 1), n);
	return s;
}

int main(void) {
	cin >> n >> k;
	long long int l(1), r(n * n + 1), m;
	while (r - l != 1) {
		m = (l + r) / 2;
		if (gc(m) < k) l = m;
		else r = m;
	}
	cout << l;
}