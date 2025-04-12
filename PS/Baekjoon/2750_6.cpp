#include<iostream>

using namespace std;

int n, ns[1'000], m, cn;

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for (int _n(0); _n < n; _n++) {
		cn = ns[_n];
		for (int _m(m = 0); _m < _n && cn > ns[_m]; _m++)
			m = _m + 1;
		for (int i(_n); i > m; i--)
			ns[i] = ns[i - 1];
		ns[m] = cn;
	}
	for (int _n(0); _n < n; _n++)
		cout << ns[_n] << '\n';
}