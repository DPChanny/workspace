#include<iostream>

using namespace std;

uint16_t n, fx, fy, tx, ty;
uint32_t m;
uint64_t ns[1025][1025];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(uint16_t _y(1); _y < n + 1; _y++)
		for(int _x(1); _x < n + 1; _x++) {
			cin >> ns[_y][_x];
			ns[_y][_x] = ns[_y - 1][_x] + ns[_y][_x - 1] - ns[_y - 1][_x - 1] + ns[_y][_x];
		}
	for(uint32_t _m(0); _m < m; _m++) {
		cin >> fy >> fx >> ty >> tx;
		cout << ns[ty][tx] - ns[ty][fx - 1] - ns[fy - 1][tx] + ns[fy - 1][fx - 1] << '\n';
	}
}