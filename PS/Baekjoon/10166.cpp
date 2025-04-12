#include<iostream>

using namespace std;

int ra, rb, c, gcd;
bool a[2001][2001];

int ggcd(int _a, int _b) {
	if(!_b) return _a;
	return ggcd(_b, _a % _b);
}

int main(void) {
	cin >> ra >> rb;
	for(int _r(ra); _r < rb + 1; _r++)
		for(int _n(1); _n < _r + 1; _n++) {
			gcd = ggcd(_r, _n);
			if(!a[_r / gcd][_n / gcd]) {
				c++;
				a[_r / gcd][_n / gcd] = true;
			}
		}
	cout << c;
}