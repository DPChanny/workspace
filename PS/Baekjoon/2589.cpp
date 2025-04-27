#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int> point;
#define py first
#define px second

int y, x, md;
bool yxs[50][50], yxvs[50][50];

bool check(int _y, int _x) {
	return
		_y + 1 > 0 && _y < y&&
		_x + 1 > 0 && _x < x&&
		yxs[_y][_x] && !yxvs[_y][_x];
}

void bfs(point _p) {
	queue<point> ps;
	int s, t(0);
	point cp;
	yxvs[_p.py][_p.px] = true;
	ps.push(_p);
	while(!ps.empty()) {
		s = ps.size();
		for(int _s(0); _s < s; _s++) {
			cp = ps.front(); ps.pop();
			if(check(cp.py + 1, cp.px)) {
				yxvs[cp.py + 1][cp.px] = true;
				ps.push({ cp.py + 1, cp.px });
			}
			if(check(cp.py - 1, cp.px)) {
				yxvs[cp.py - 1][cp.px] = true;
				ps.push({ cp.py - 1, cp.px});
			}
			if(check(cp.py, cp.px + 1)) {
				yxvs[cp.py][cp.px + 1] = true;
				ps.push({ cp.py, cp.px + 1});
			}
			if(check(cp.py, cp.px - 1)) {
				yxvs[cp.py][cp.px - 1] = true;
				ps.push({ cp.py, cp.px - 1});
			}
		}
		t++;
	}
	md = max(t, md);
}

int main(void) {
	cin >> y >> x;
	for(int _y(0); _y < y; _y++) {
		getchar();
		for(int _x(0); _x < x; _x++)
			yxs[_y][_x] = getchar() == 'L';
	}
	for(int _y(0); _y < y; _y++)
		for(int _x(0); _x < x; _x++)
			if(yxs[_y][_x]) {
				memset(yxvs, false, sizeof(yxvs));
				bfs({ _y, _x });
			}
	cout << md - 1;
}