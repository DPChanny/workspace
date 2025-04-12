#include<iostream>
#include<cstring>

using namespace std;

constexpr int MAX_HEIGHT = 100;
constexpr int MIN_HEIGHT = 0;

int
	hn(MIN_HEIGHT),
	ln(MAX_HEIGHT),
	n,
	ns[100][100],
	nv[100][100],
	c,
	mc(0);

bool check(int _y, int _x, int _h) {
	return
		_y + 1 > 0 && _y < n&&
		_x + 1 > 0 && _x < n&&
		nv[_y][_x] != _h &&
		ns[_y][_x] > _h;
}

void fill(int _y, int _x, int _h) {
	if (check(_y, _x, _h)) {
		nv[_y][_x] = _h;
		fill(_y + 1, _x, _h);
		fill(_y - 1, _x, _h);
		fill(_y, _x + 1, _h);
		fill(_y, _x - 1, _h);
	}
}

int main(void){
	memset(nv, -1, sizeof(nv));
	cin >> n;
	for (int _y(0); _y < n; _y++)
		for (int _x(0); _x < n; _x++) {
			cin >> ns[_y][_x];
			hn = max(ns[_y][_x], hn);
			ln = min(ns[_y][_x], ln);
		}
	for (int _h(ln - 1); _h < hn + 1; _h++) {
		c = 0;
		for (int _y(0); _y < n; _y++)
			for (int _x(0); _x < n; _x++)
				if (check(_y, _x, _h)) {
					fill(_y, _x, _h);
					c++;
				}
		mc = max(mc, c);
	}
	cout << mc;
}