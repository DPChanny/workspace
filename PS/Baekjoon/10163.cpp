#include<iostream>

using namespace std;

int n, ns[1001][1001], xa, ya, h, w, rs[100];

int main(void) {
	cin >> n;
	for(int _n(0); _n < n; _n++) {
		cin >> xa >> ya >> w >> h;
		for(int _h(0); _h < h; _h++)
			for(int _w(0); _w < w; _w++)
				ns[ya + _h][xa + _w] = _n + 1;
	}
	for(int _y(0); _y < 1001; _y++)
		for(int _x(0); _x < 1001; _x++)
			if(ns[_y][_x]) rs[ns[_y][_x] - 1]++;
	for(int _n(0); _n < n; _n++)
		cout << rs[_n] << '\n';
}