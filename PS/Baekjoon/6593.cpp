#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int m[30][30][30], x, y, h, s;
bool vs[30][30][30];

struct S {
	int y,
		x,
		h;
};

bool check(S _s) {
	return 
		_s.h + 1 > 0 && _s.h < h && 
		_s.x + 1 > 0 && _s.x < x &&
		_s.y + 1 > 0 && _s.y < y &&
		!vs[_s.h][_s.y][_s.x] && m[_s.h][_s.y][_s.x] != '#';
}

int main(void) {
	while (true) {
		cin >> h >> y >> x; getchar();
		if (!x && !y && !h) exit(EXIT_SUCCESS);
		queue<S> q;
		for (int _h(0); _h < h; _h++){
			for (int _y(0); _y < y; _y++) {
				for (int _x(0); _x < x; _x++) {
					m[_h][_y][_x] = getchar();
					if (m[_h][_y][_x] == 'S')
						q.push({ _y, _x, _h });
				} getchar();
			} getchar();
		}
		int t(0);
		S c;
		bool flag(false);
		while (!q.empty()) {
			s = q.size();
			for (int _s(0); _s < s; _s++) {
				c = q.front(); q.pop();
				if (m[c.h][c.y][c.x] == 'E') {
					flag = true;
					cout << "Escaped in " << t << " minute(s).\n";
					break;
				}
				if (check({c.y + 1, c.x, c.h})) {
					vs[c.h][c.y + 1][c.x] = true;
					q.push({ c.y + 1, c.x, c.h });
				}
				if (check({ c.y - 1, c.x, c.h })) {
					vs[c.h][c.y - 1][c.x] = true;
					q.push({ c.y - 1, c.x, c.h });
				}
				if (check({ c.y, c.x + 1, c.h })) {
					vs[c.h][c.y][c.x + 1] = true;
					q.push({ c.y, c.x + 1, c.h });
				}
				if (check({ c.y, c.x - 1, c.h })) {
					vs[c.h][c.y][c.x - 1] = true;
					q.push({ c.y, c.x - 1, c.h });
				}
				if (check({ c.y, c.x, c.h + 1 })) {
					vs[c.h + 1][c.y][c.x] = true;
					q.push({ c.y, c.x, c.h + 1 });
				}
				if (check({ c.y, c.x, c.h - 1 })) {
					vs[c.h - 1][c.y][c.x] = true;
					q.push({ c.y, c.x, c.h - 1 });
				}
			}
			if (flag) break;
			t++;
		}
		if(!flag) cout << "Trapped!\n";
		memset(vs, false, sizeof(vs));
	}
}