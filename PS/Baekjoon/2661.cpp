#include<iostream>

using namespace std;

int n, ns[80];

void ggs(int _n, int _v) {
	ns[_n - 1] = _v;
	for(int __n(1); __n < _n / 2 + 1; __n++)
		if(equal(ns + _n - __n, ns + _n, ns + _n - 2 * __n)) return;
	if(_n == n) {
		for(int _n(0); _n < n; _n++)
			cout << ns[_n];
		exit(EXIT_SUCCESS);
	}
	ggs(_n + 1, 1);
	ggs(_n + 1, 2);
	ggs(_n + 1, 3);
}

int main(void) {
	cin >> n;
	ggs(1, 1);
	ggs(1, 2);
	ggs(1, 3);
}