#include<iostream>

using namespace std;

enum class S {
	a = -1,
	b, c, m
};

int n, ns[2187][2187], cs[3];

S gc(int _n, int _y, int _x) {
	if(_n == 1) return (S)ns[_y][_x];
	S ss[9]{
		gc(_n / 3, _y, _x),
		gc(_n / 3, _y + _n / 3, _x),
		gc(_n / 3, _y, _x + _n / 3),
		gc(_n / 3, _y + 2 * _n / 3, _x),
		gc(_n / 3, _y, _x + 2 * _n / 3),
		gc(_n / 3, _y + _n / 3, _x + _n / 3),
		gc(_n / 3, _y + 2 * _n / 3, _x + 2 * _n / 3),
		gc(_n / 3, _y + _n / 3, _x + 2 * _n / 3),
		gc(_n / 3, _y + 2 * _n / 3, _x + _n / 3),
	};
	if(equal(ss + 1, ss + 9, ss)) return ss[0];
	for(int _s(0); _s < 9; _s++)
		if(ss[_s] != S::m) cs[(int)ss[_s] + 1]++;
	return S::m;
}

int main(void) {
	cin >> n;
	for(int _y(0); _y < n; _y++)
		for(int _x(0); _x < n; _x++)
			cin >> ns[_y][_x];
	S s = gc(n, 0, 0);
	if(s != S::m) cs[(int)s + 1]++;
	cout << cs[0] << '\n' << cs[1] << '\n' << cs[2];
}