#include<iostream>
#include<queue>

using namespace std;

int x, y, ns[300][300], s, t(0), ds[2][2]{ {1, 0}, {0, 1} }, tx, ty;
bool v[300][300]{ false, };

bool check(int _y, int _x) {
	return
		_y + 1 > 0 && _y < y&&
		_x + 1 > 0 && _x < x;
}

int main(void) {
	cin >> y >> x;
	for (int _y(0); _y < y; _y++)
		for (int _x(0); _x < x; _x++)
			cin >> ns[_y][_x];
	queue<pair<int, int>> q;
	pair<int, int> cq;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			cq = q.front(); q.pop();
			if (cq.first == y - 1 && cq.second == x - 1) {
				cout << t;
				exit(EXIT_SUCCESS);
			}
			for (int _d(0); _d < 2; _d++) {
				for (int _n(1); _n < ns[cq.first][cq.second] + 1; _n++) {
					ty = cq.first + ds[_d][0] * _n;
					tx = cq.second + ds[_d][1] * _n;
					if (check(ty, tx)) {
						if (!v[ty][tx]) {
							v[ty][tx] = true;
							q.push(make_pair(ty, tx));
						}
					}
					else break;
				}
			}
		}
		t++;
	}
}