#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n, mt(1e3);
bool ns[100][100], vs[100][100], nsc[100][100];
queue<pair<int, int>> q;

bool check_pos(int _y, int _x) {
	return
		_y + 1 > 0 && _y < n&&
		_x + 1 > 0 && _x < n &&
		!vs[_y][_x];
}

void find_edge(int _y, int _x) {
	if (!check_pos(_y, _x)) return;
	vs[_y][_x] = true;
	if (!ns[_y][_x]) {
		q.push(make_pair(_y, _x));
		return;
	}
	nsc[_y][_x] = false;
	find_edge(_y + 1, _x);
	find_edge(_y - 1, _x);
	find_edge(_y, _x + 1);
	find_edge(_y, _x - 1);
}

int find_bridge() {
	int t(0), s;
	pair<int, int> cq;
	while (!q.empty()) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			cq = q.front(); q.pop();
			if (ns[cq.first][cq.second]) return t;
			if (check_pos(cq.first + 1, cq.second)) {
				vs[cq.first + 1][cq.second] = true;
				q.push(make_pair(cq.first + 1, cq.second));
			}
			if (check_pos(cq.first - 1, cq.second)) {
				vs[cq.first - 1][cq.second] = true;
				q.push(make_pair(cq.first - 1, cq.second));
			}
			if (check_pos(cq.first, cq.second + 1)) {
				vs[cq.first][cq.second + 1] = true;
				q.push(make_pair(cq.first, cq.second + 1));
			}
			if (check_pos(cq.first, cq.second - 1)) {
				vs[cq.first][cq.second - 1] = true;
				q.push(make_pair(cq.first, cq.second - 1));
			}
		}
		t++;
	}
}

int main(void) {
	cin >> n;
	for (int _y(0); _y < n; _y++)
		for (int _x(0); _x < n; _x++)
			cin >> ns[_y][_x];
	memcpy(nsc, ns, sizeof(ns));
	for (int _y(0); _y < n; _y++)
		for (int _x(0); _x < n; _x++)
			if (nsc[_y][_x]) {
				find_edge(_y, _x);
				mt = min(find_bridge(), mt); 
				q = queue<pair<int, int>>();
				memset(vs, false, sizeof(vs));
			}
	cout << mt;
}
