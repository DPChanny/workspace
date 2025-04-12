#include<iostream>

using namespace std;

int main(void) {
	int n, s(0), ns[1000];
	cin >> n;
	for (int _n(0); _n < n; _n++) {
		cin >> ns[_n];
		s += ns[_n];
	} 
	s /= 2;
	for (int _n(0); _n < n; _n++) {
		int _s(s);
		for (int i(_n + 1); i % n != _n; i += 2)
			_s -= ns[i % n];
		cout << _s << '\n';
	}
}