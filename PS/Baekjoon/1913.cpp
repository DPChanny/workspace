#include<iostream>

using namespace std;

const int dir[4][2] = { {0, 1} , {1, 0 }, {0, -1}, {-1, 0} };

int n, nt, ns[1000][1000], ntx, nty;

void place_n(int _y, int _x, int _n) {
	if (_n < 0) return;
	ns[_y][_x] = _n * _n;
	if (ns[_y][_x] == nt) {
		ntx = _x;
		nty = _y;
	}
	for (int _d(0); _d < 4; _d++) {
		for (int __n(0); __n < _n - 1 - (_d == 3); __n++) {
			ns[_y + dir[_d][1]][_x + dir[_d][0]] = ns[_y][_x] - 1;
			_y += dir[_d][1];
			_x += dir[_d][0]; 
			if (ns[_y][_x] == nt) {
				ntx = _x;
				nty = _y;
			}
		}
	}
	place_n(_y + 1, _x, _n - 2);
}

int main(void) {
	cin >> n >> nt;
	place_n(0, 0, n);
	for (int _y(0); _y < n; _y++) {
		for (int _x(0); _x < n; _x++)
			cout << ns[_y][_x] << ' ';
		cout << '\n';
	}
	cout << nty + 1<< ' ' << ntx + 1;
}