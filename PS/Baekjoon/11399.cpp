#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int n,
		s(0),
		ns[1000];
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	for (int _n(0); _n < n; _n++)
		for (int _i(0); _i < _n + 1; _i++)
			s += ns[_i];
	cout << s;
}