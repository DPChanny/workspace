#include<iostream>

using namespace std;

int buf[2187][2187];

void p(int _y, int _x, int _n) {
	if (_n == 1) {
		buf[_y][_x] = 1;
		return;
	}
	p(_y, _x, _n / 3);
	p(_y, _x + _n / 3, _n / 3);
	p(_y, _x + 2 * (_n / 3), _n / 3);
	p(_y + _n / 3, _x, _n / 3);
	p(_y + _n / 3, _x + 2 * (_n / 3), _n / 3);
	p(_y + 2 * (_n / 3), _x, _n / 3);
	p(_y + 2 * (_n / 3), _x + _n / 3, _n / 3);
	p(_y + 2 * (_n / 3), _x + 2 * (_n / 3), _n / 3);
}

int main(void) {
	int n;
	cin >> n;
	p(0, 0, n);
	for (int _y(0); _y < n; _y++) {
		for (int _x(0); _x < n; _x++)
			cout << (buf[_y][_x] ? '*' : ' ');
		cout << '\n';
	}
}