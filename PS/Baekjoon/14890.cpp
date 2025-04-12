#include<iostream>
#include<vector>

using namespace std;

typedef long long int lli;

lli yx, l, yxs[100][100], r;

//check row
bool cy(lli _y) {
	vector<bool> vs(yx, false);
	lli _x(0);
	while (_x != yx - 1) {
		if (yxs[_y][_x] != yxs[_y][_x + 1]) {
			if (abs(yxs[_y][_x] - yxs[_y][_x + 1]) > 1) return false;
			if (yxs[_y][_x] > yxs[_y][_x + 1]) {
				if (_x + l > yx - 1) return false;
				for (lli _l(0); _l < l; _l++) {
					if (yxs[_y][_x + 1] != yxs[_y][_x + 1 + _l]) return false;
					vs[_x + 1 + _l] = true;
				}
				_x += l;
			}
			if (yxs[_y][_x] < yxs[_y][_x + 1]) {
				if (l > _x + 1) return false;
				for (lli _l(0); _l < l; _l++) {
					if (yxs[_y][_x] != yxs[_y][_x - _l]) return false;
					if (vs[_x - _l]) return false;
				}
				_x++;
			}
		}
		else _x++;
	}
	return true;
}

//check column
bool cx(lli _x) {
	vector<bool> vs(yx, false);
	lli _y(0);
	while (_y != yx - 1) {
		if (yxs[_y][_x] != yxs[_y + 1][_x]) {
			if (abs(yxs[_y][_x] - yxs[_y + 1][_x]) > 1) return false;
			if (yxs[_y][_x] > yxs[_y + 1][_x]) {
				if (_y + l > yx - 1) return false;
				for (lli _l(0); _l < l; _l++) {
					if (yxs[_y + 1][_x] != yxs[_y + 1 + _l][_x]) return false;
					vs[_y + 1 + _l] = true;
				}
				_y += l;
			}
			if (yxs[_y][_x] < yxs[_y + 1][_x]) {
				if (l > _y + 1) return false;
				for (lli _l(0); _l < l; _l++) {
					if (yxs[_y][_x] != yxs[_y - _l][_x]) return false;
					if (vs[_y - _l]) return false;
				}
				_y++;
			}
		} else _y++;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> yx >> l;
	for (lli _y(0); _y < yx; _y++)
		for (lli _x(0); _x < yx; _x++)
			cin >> yxs[_y][_x];
	for (lli _y(0); _y < yx; _y++)
		if (cy(_y)) r++; 
	for (lli _x(0); _x < yx; _x++)
		if (cx(_x)) r++;
	cout << r;
}