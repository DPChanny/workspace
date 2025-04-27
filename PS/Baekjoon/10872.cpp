#include<iostream>

using namespace std;

int f(int _n) {
	if (!_n) return 1;
	return f(_n - 1) * _n;
}

int main(void) {
	int n;
	cin >> n;
	cout << f(n);
}