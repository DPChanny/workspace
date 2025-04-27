#include<iostream>

using namespace std;

int a, b, c;

unsigned long long int m(int _r) {
	if (!_r) return 1;
	unsigned long long int r(m(_r / 2));
	r *= r;
	r %= c;
	return r * ((_r % 2) ? a : 1) % c;
}

int main(void) {
	cin >> a >> b >> c;
	cout << m(b) << '\n';
}
