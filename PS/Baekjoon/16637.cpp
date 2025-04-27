#include<iostream>
#include<vector>

using namespace std;

typedef long long int lli;

string s;

lli c(lli _a, lli _b, char _o) {
	if (_o == '+') return _a + _b;
	if (_o == '-') return _a - _b;
	if (_o == '*') return _a * _b;
}

lli gm(lli _o, lli _s, bool _f) {
	if (_o == s.size()) return c(_s, s[_o - 1] - '0', s[_o - 2]);
	if (_o > s.size()) return _s;
	if (_f) return max(
		gm(_o + 4, c(_s, c(s[_o - 1] - '0', s[_o + 1] - '0', s[_o]), s[_o - 2]), false),
		gm(_o + 4, c(_s, c(s[_o - 1] - '0', s[_o + 1] - '0', s[_o]), s[_o - 2]), true));
	else return max(
		gm(_o + 2, c(_s, s[_o - 1] - '0', s[_o - 2]), false),
		gm(_o + 2, c(_s, s[_o - 1] - '0', s[_o - 2]), true));
}

int main(void) {
	cin >> s >> s;
	s = '+' + s;
	cout << max(gm(2, 0, false), gm(2, 0, true));
}