#include<iostream>
#include<queue>

using namespace std;

int ts[100][100][100],
	x,
	y,
	h;

struct T {
	int y,
		x,
		h;
};

int main(void) {
	int t(0), s;
	cin >> x >> y >> h;
	queue<T> q; 
	for (int _h(0); _h < h; _h++)
		for (int _y(0); _y < y; _y++)
			for (int _x(0); _x < x; _x++) {
				cin >> ts[_h][_y][_x];
				if (ts[_h][_y][_x] == 1)
					q.push({ _y, _x, _h });
			}
	T c;
	while (!q.empty()) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			c = q.front(); q.pop();
			ts[c.h][c.y][c.x] = 1;
			if (c.y + 1 < y && !ts[c.h][c.y + 1][c.x]) {
				ts[c.h][c.y + 1][c.x] = 1;
				q.push({ c.y + 1, c.x, c.h });
			}
			if (c.y > 0 && !ts[c.h][c.y - 1][c.x]) {
				ts[c.h][c.y - 1][c.x] = 1;
				q.push({ c.y - 1, c.x, c.h });
			}
			if (c.x + 1 < x && !ts[c.h][c.y][c.x + 1]) {
				ts[c.h][c.y][c.x + 1] = 1;
				q.push({ c.y, c.x + 1, c.h });
			}
			if (c.x > 0 && !ts[c.h][c.y][c.x - 1]) {
				ts[c.h][c.y][c.x - 1] = 1;
				q.push({ c.y, c.x - 1, c.h });
			}
			if (c.h + 1 < h && !ts[c.h + 1][c.y][c.x]) {
				ts[c.h + 1][c.y][c.x] = 1;
				q.push({ c.y, c.x, c.h + 1});
			}
			if (c.h > 0 && !ts[c.h - 1][c.y][c.x]) {
				ts[c.h - 1][c.y][c.x]= 1;
				q.push({ c.y, c.x, c.h - 1});
			}
		}
		t++;
	} 
	for (int _h(0); _h < h; _h++)
		for (int _y(0); _y < y; _y++)
			for (int _x(0); _x < x; _x++)
				if (!ts[_h][_y][_x]) {
					cout << -1;
					return 0;
				}
	cout << t - 1;
}