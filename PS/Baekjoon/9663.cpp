#include<iostream>

using namespace std;

int n, c;
bool qxs[15], qs[15][15], f;

bool cp(const int& _y, const int& _x) {
	return
		_y + 1 > 0 && _y < n&&
		_x + 1 > 0 && _x < n;
}

void fq(int _n) {
	if(_n == n) {
		c++;
		return;
	}
	for(int _x(0); _x < n; _x++) {
		if(!qxs[_x]) {
			f = false;
			for(int _y(1); _n - _y + 1 > 0; _y++) {
				if(cp(_n - _y, _x - _y))
					if(qs[_n - _y][_x - _y]) {
						f = true;
						break;
					}
				if(cp(_n - _y, _x + _y))
					if(qs[_n - _y][_x + _y]) {
						f = true;
						break;
					}
			}
			if(f) continue;
			else {
				qs[_n][_x] = true;
				qxs[_x] = true;
				fq(_n + 1);
				qs[_n][_x] = false;
				qxs[_x] = false;
			}
		}
	}
}

int main(void) {
	cin >> n;
	fq(0);
	cout << c;
}