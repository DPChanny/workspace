#include<iostream>

using namespace std;

int n, ns[1'000];
bool s(true);

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	while (s) {
		s = false;
		for (int _n(0); _n < n - 1; _n++)
			if (ns[_n] > ns[_n + 1]) {
				swap(ns[_n], ns[_n + 1]);
				s = true;
			}
	}
	for (int _n(0); _n < n; _n++)
		cout << ns[_n] << '\n';
}