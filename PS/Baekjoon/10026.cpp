#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

#define R 'R'
#define G 'G'
#define B 'B'

int n, c(0);
char ns[100][100];
bool nv[100][100]{ false, };

bool check(int _y, int _x, char _t, bool _blind) {
	bool visit =
		_y + 1 > 0 && _y < n&&
		_x + 1 > 0 && _x < n &&
		!nv[_y][_x];
	bool passage = _blind ?
		((_t == B) ?
			(ns[_y][_x] == B) :
			(ns[_y][_x] != B)) :
		(ns[_y][_x] == _t);
	return visit && passage;
}

void fill(int _y, int _x, bool _blind) {
	char t(ns[_y][_x]);
	nv[_y][_x] = true;
	queue<pair<int, int>> q;
	pair<int, int> cq;
	q.push(make_pair(_y, _x));
	while (!q.empty()) {
		cq = q.front(); q.pop();
		if (check(cq.first + 1, cq.second, t, _blind)) {
			nv[cq.first + 1][cq.second] = true;
			q.push(make_pair(cq.first + 1, cq.second));
		}if (check(cq.first - 1, cq.second, t, _blind)) {
			nv[cq.first - 1][cq.second] = true;
			q.push(make_pair(cq.first - 1, cq.second));
		}if (check(cq.first, cq.second + 1, t, _blind)) {
			nv[cq.first][cq.second + 1] = true;
			q.push(make_pair(cq.first, cq.second + 1));
		}if (check(cq.first, cq.second - 1, t, _blind)) {
			nv[cq.first][cq.second - 1] = true;
			q.push(make_pair(cq.first, cq.second - 1));
		}
	}
}

int main(void) {
	cin >> n;
	for (int _y(0); _y < n; _y++) {
		getchar();
		for (int _x(0); _x < n; _x++)
			ns[_y][_x] = getchar();
	}
	for (int _y(0); _y < n; _y++)
		for (int _x(0); _x < n; _x++)
			if (!nv[_y][_x]) {
				fill(_y, _x, false); c++;
			}
	cout << c; c = 0;
	memset(nv, false, sizeof(nv));
	for (int _y(0); _y < n; _y++)
		for (int _x(0); _x < n; _x++)
			if (!nv[_y][_x]) {
				fill(_y, _x, true); c++;
			}
	cout << ' ' << c;
}