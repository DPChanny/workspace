#include<iostream>
#include<queue>

using namespace std;

int t, x, y, k, bx, by, c;
bool m[50][50]{ false, };

bool check(int _y, int _x) {
	return
		_y + 1 > 0 && _y < y&&
		_x + 1 > 0 && _x < x&&
		m[_y][_x];
}

void fill(int _y, int _x) {
	if (check(_y, _x)) {
		m[_y][_x] = false;
		fill(_y + 1, _x);
		fill(_y - 1, _x);
		fill(_y, _x + 1);
		fill(_y, _x - 1);
	}
}

int main(void) {
	cin >> t;
	for (int _t(0); _t < t; _t++) {
		c = 0;
		cin >> x >> y >> k;
		for (int _k(0); _k < k; _k++) {
			cin >> bx >> by;
			m[by][bx] = true;
		}
		for (int _y(0); _y < y; _y++) {
			for (int _x = 0; _x < x; _x++) {
				if (m[_y][_x]) {
					c++;
					fill(_y, _x);
				}
			}
		}
		cout << c << '\n';
	}
}