#include<iostream>
#include<queue>

using namespace std;

int ts[1000][1000],
	x,
	y;

int main(void) {
	int t(0), s;
	cin >> x >> y;
	queue<pair<int, int>> q;
	for (int _y(0); _y < y; _y++)
		for (int _x(0); _x < x; _x++) {
			cin >> ts[_y][_x];
			if (ts[_y][_x] == 1)
				q.push({_y, _x});
		}
	pair<int, int> c;
	while (!q.empty()) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			c = q.front(); q.pop();
			ts[c.first][c.second] = 1;
			if (c.first + 1 < y && !ts[c.first + 1][c.second]) {
				ts[c.first + 1][c.second] = 1;
				q.push({ c.first + 1, c.second });
			}
			if (c.first > 0 && !ts[c.first - 1][c.second]) {
				ts[c.first - 1][c.second] = 1;
				q.push({ c.first - 1, c.second });
			}
			if (c.second + 1 < x && !ts[c.first][c.second + 1]) {
				ts[c.first][c.second + 1] = 1;
				q.push({ c.first, c.second + 1 });
			}
			if (c.second > 0 && !ts[c.first][c.second - 1]) {
				ts[c.first][c.second - 1] = 1;
				q.push({ c.first, c.second - 1 });
			}
		}
		t++;
	}
	for (int _y(0); _y < y; _y++)
		for (int _x(0); _x < x; _x++)
			if (!ts[_y][_x]) {
				cout << -1;
				return 0;
			}
	cout << t - 1;
}