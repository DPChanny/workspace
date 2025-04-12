#include<iostream>
#include<vector>
#include<cmath>

constexpr int N = 9;

using namespace std;

struct b {
	int y, x;
	vector<int> ps;
};

int ns[N][N];
vector<b> bs;

vector<int> gps(const int& _y, const int& _x) {
	bool ps[N + 1]{ false, };
	for(int __x(0); __x < N; __x++)
		ps[ns[_y][__x]] = true;
	for(int __y(0); __y < N; __y++)
		ps[ns[__y][_x]] = true;
	for(int __y(0); __y < sqrt(N); __y++)
		for(int __x(0); __x < sqrt(N); __x++)
			ps[ns[_y / 3 * 3 + __y][_x / 3 * 3 + __x]] = true;
	vector<int> r;
	for(int _n(0); _n < N; _n++)
		if(!ps[_n + 1]) r.push_back(_n + 1);
	return r;
}

bool cp(const int& _y, const int& _x, const int& _n) {
	for(int __x(0); __x < N; __x++)
		if(ns[_y][__x] == _n) return false;
	for(int __y(0); __y < N; __y++)
		if(ns[__y][_x] == _n) return false;
	for(int __y(0); __y < sqrt(N); __y++)
		for(int __x(0); __x < sqrt(N); __x++)
			if(ns[_y / 3 * 3 + __y][_x / 3 * 3 + __x] == _n) return false;
	return true;
}

void gns(int _b) {
	if(_b == bs.size()) {
		for(int _y(0); _y < N; _y++) {
			for(int _x(0); _x < N; _x++)
				cout << ns[_y][_x] << ' ';
			cout << '\n';
		}
		exit(EXIT_SUCCESS);
	}
	for(int _p(0); _p < bs[_b].ps.size(); _p++) {
		if(cp(bs[_b].y, bs[_b].x, bs[_b].ps[_p])) {
			ns[bs[_b].y][bs[_b].x] = bs[_b].ps[_p];
			gns(_b + 1);
			ns[bs[_b].y][bs[_b].x] = 0;
		}
	}
}

int main(void) {
	for(int _y(0); _y < N; _y++)
		for(int _x(0); _x < N; _x++)
			cin >> ns[_y][_x];
	for(int _y(0); _y < N; _y++)
		for(int _x(0); _x < N; _x++)
			if(!ns[_y][_x]) bs.push_back({ _y, _x, gps(_y, _x) });
	gns(0);
}