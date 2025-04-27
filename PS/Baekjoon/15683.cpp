#include<iostream>
#include<vector>

using namespace std;

struct c{
	pair<int, int> p;
	int t;
};

#define py first
#define px second

constexpr pair<int, int> r = { 0, 1 };
constexpr pair<int, int> l = { 0, -1 };
constexpr pair<int, int> u = { 1, 0 };
constexpr pair<int, int> d = { -1, 0 };
constexpr int w = 6;

pair<int, int> operator+(const pair<int, int>& _a, const pair<int, int>& _b) {
	return { _a.py + _b.py, _a.px + _b.px };
}
pair<int, int> operator*(const int& _a, const pair<int, int>& _b) {
	return { _a * _b.py, _a * _b.px };
}

pair<int, int> ds[5][4][4]{
	{ {r}, {l}, {u}, {d} },
	{ {r, l}, {u, d} },
	{ {r, u}, {l, u}, {r, d}, {l, d} },
	{ {r, l, u}, {r, u, d}, {r, l, d}, {l, u, d} },
	{ {r, l, u, d} } };
pair<int, int> dcs[5]{ {4, 1}, {2, 2}, {4, 2}, {4, 3}, {1, 4} };
vector<c> cs;

int y, x, yxs[8][8], yxvs[8][8], mr(64);

bool cp(const pair<int, int>& _a) {
	return
		_a.px + 1 > 0 && _a.px < x &&
		_a.py + 1 > 0 && _a.py < y &&
		yxs[_a.py][_a.px] != w;
}

void grm(int _c) {
	if(_c == cs.size()) {
		int r(0);
		for(int _y(0); _y < y; _y++)
			for(int _x(0); _x < x; _x++)
				if(!yxvs[_y][_x] && yxs[_y][_x] != 6) r++;
		mr = min(mr, r);
		return;
	}
	c& c = cs[_c];
	pair<int, int> p;
	for(int _i(0); _i < dcs[c.t].first; _i++) {
		for(int _j(0); _j < dcs[c.t].second; _j++)
			for(int _k(0); cp(p = c.p + _k * ds[c.t][_i][_j]); _k++)
				yxvs[p.py][p.px]++;
		grm(_c + 1);
		for(int _j(0); _j < dcs[c.t].second; _j++)
			for(int _k(0); cp(p = c.p + _k * ds[c.t][_i][_j]); _k++)
				yxvs[p.py][p.px]--;
	}
}

int main(void) {
	cin >> y >> x;
	for(int _y(0); _y < y; _y++)
		for(int _x(0); _x < x; _x++) {
			cin >> yxs[_y][_x];
			if(yxs[_y][_x] && w != yxs[_y][_x])
				cs.push_back({ {_y, _x}, yxs[_y][_x] - 1 });
		}
	grm(0);
	cout << mr;
}