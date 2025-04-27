#include<iostream>
#include<algorithm>

using namespace std;

int n, ns[1'000];

void swap(int* _a, int* _b) {
	int tmp = *_a;
	*_a = *_b;
	*_b = tmp;
}

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for (int _n(0); _n < n; _n++) {
		swap(ns + _n, min_element(ns + _n, ns + n));
		cout << ns[_n] << '\n';
	}
}