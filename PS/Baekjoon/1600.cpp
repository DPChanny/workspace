#include<iostream>
#include<queue>

using namespace std;;

int k, y, x, s, t, vs[200][200][31];
bool ns[200][200];

struct N {
	int y, x, k;
	N operator+(const N& _n) {
		return { y + _n.y, x + _n.x, k + _n.k };
	}
};

const N ds[12] = {
	{1, 2, -1}, {-1, 2, -1}, {1, -2, -1}, {-1, -2, -1},
	{2, 1, -1}, {2, -1, -1}, {-2, 1, -1}, {-2, -1, -1},
	{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0} };

bool check(const N& _n) {
	return
		_n.y + 1 > 0 && _n.y < y &&
		_n.x + 1 > 0 && _n.x < x &&
		!ns[_n.y][_n.x] && !vs[_n.y][_n.x][_n.k];
}

int main(void) {
	cin >> k >> x >> y;
	for (int _y(0); _y < y; _y++)
		for (int _x(0); _x < x; _x++)
			cin >> ns[_y][_x];
	queue<N> q;
	N cq, nq;
	q.push({ 0, 0, k });
	while (!q.empty()) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			cq = q.front();  q.pop();
			if (cq.y + 1 == y && 
				cq.x + 1 == x) {
				cout << t;
				exit(EXIT_SUCCESS);
			}
			for (int _d(8 * (cq.k ? 0 : 1)); _d < 12; _d++) {
				nq = cq + ds[_d];
				if (check(nq)) {
					vs[nq.y][nq.x][nq.k] = true;
					q.push(nq);
				}
			}
		}
		t++;
	}
	cout << -1;
}