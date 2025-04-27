#include<iostream>
#include<algorithm>

using namespace std;

int m, n, ns[1'000'000];

int gc(int _l) {
	int c(0);
	for(int _n(n - 1); _n + 1 > 0 && ns[_n] + 1 > _l; _n--)
		c += ns[_n] / _l;
	return c;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);

	int sl(1), el(1'000'000'000), ml, c;
	while(sl != el) {
		ml = (sl + el) / 2;
		c = gc(ml);
		if(c < m) el = ml;
		else sl = ml + 1;
	}
	cout << sl - 1;
}