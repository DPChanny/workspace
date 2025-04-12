#include<iostream>
#include<algorithm>

using namespace std;

int n, io[100'000], po[100'000];

void mt(int* _io, int* _po, const long long int& _s) {
	if (!_s) return;
	cout << _po[_s - 1] << ' ';
	int* m = find(_io, _io + _s, _po[_s - 1]);
	mt(_io, _po, m - _io);
	mt(m + 1, _po + (m - _io), _s - (m - _io) - 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> io[_n];
	for (int _n(0); _n < n; _n++)
		cin >> po[_n];
	mt(io, po, n);
}