#include<iostream>

using namespace std;

int n, y, x, c;

void gc(int _s, int _y, int _x) {
	if(_s == 1) {
		if(_y == y && _x == x) {
			cout << c;
			exit(EXIT_SUCCESS);
		}
		c++;
		return;
	}
	if(x > _x + _s * _s || y > _y + _s * _s) {
		c += _s * _s;
		return;
	}
	gc(_s >> 1, _y, _x);
	gc(_s >> 1, _y, _x + (_s >> 1));
	gc(_s >> 1, _y + (_s >> 1), _x);
	gc(_s >> 1, _y + (_s >> 1), _x + (_s >> 1));
}

int main(void) {
	cin >> n >> y >> x;
	gc(1 << n, 0, 0);
}