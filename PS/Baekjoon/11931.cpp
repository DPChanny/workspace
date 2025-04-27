#include<iostream>

using namespace std;

int n, ns[1'000'000];

void m(int* _l, int* _m, int* _r) {
	int* il(_l), * ir(_m), * t(new int[_r - _l]), * it(t);
	while (il != _m && ir != _r) 
		*it++ = *il < *ir ? *il++ : *ir++;
	while (il != _m) *it++ = *il++;
	while (ir != _r) *it++ = *ir++;
	it = t; il = _l;
	while (il != _r) *il++ = *it++;
	delete[] t;
}

void ms(int* _l, int* _r) {
	if (!(_r - _l - 1)) return;
	ms(_l, _l + (_r - _l) / 2);
	ms(_l + (_r - _l) / 2, _r);
	m(_l, _l + (_r - _l) / 2, _r);
}

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	ms(ns, ns + n);
	for (int _n(n - 1); _n + 1 > 0; _n--)
		cout << ns[_n] << '\n';
}