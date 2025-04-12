#include<iostream>
#include<queue>

using namespace std;

int m[100][100];

int main(void) {
	int y, x, s, t(0);
	queue<pair<int, int>> q;
	cin >> y >> x;
	for (int _y(0); _y < y; _y++) {
		getchar();
		for (int _x(0); _x < x; _x++)
			m[_y][_x] = getchar() - '0';
	}
	q.push({ 0, 0 });
	pair<int, int> c;
	while(!q.empty()){
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			c = q.front(); q.pop();
			if (c.first == y - 1 && c.second == x - 1) {
				cout << t + 1;
				return 0;
			}
			if (c.first > 0 && m[c.first - 1][c.second]) {
				m[c.first - 1][c.second] = 0;
				q.push({c.first - 1, c.second});
			}
			if (c.first + 1 < y && m[c.first + 1][c.second]) {
				m[c.first + 1][c.second] = 0;
				q.push({ c.first + 1, c.second });
			}
			if (c.second > 0 && m[c.first][c.second - 1]) {
				m[c.first][c.second - 1] = 0;
				q.push({ c.first, c.second - 1 });
			}
			if (c.second + 1 < x && m[c.first][c.second + 1]) {
				m[c.first][c.second + 1] = 0;
				q.push({ c.first, c.second + 1 });
			}
		}
		t++;
	}
}
