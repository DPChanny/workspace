#include<iostream>

using namespace std;

uint64_t n, r;

int main(void) {
	cin >> n;
	for(uint64_t _n(1); _n < n; _n++)
		r += n * _n + _n;
	cout << r;
}