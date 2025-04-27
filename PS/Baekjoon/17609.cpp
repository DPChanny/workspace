#include<iostream>

using namespace std;

typedef long long int lli;

lli t;
string s;

lli gc(lli _l, lli _r, lli _c) {
	while (_l < _r && _c < 2) {
		if (s[_l] != s[_r]) {
			lli sl = gc(_l + 1, _r, _c + 1), sb = gc(_l, _r - 1, _c + 1);
			return min(sl, sb);
		}
		_l++; _r--;
	}
	return _c;
}

int main(void) {
	cin >> t;
	for (lli _t(0); _t < t; _t++) {
		cin >> s;
		cout << gc(0, s.size() - 1, 0) << '\n';
	}
}