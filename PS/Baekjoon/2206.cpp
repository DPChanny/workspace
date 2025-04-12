#include<iostream>
#include<queue>

using namespace std;

int y, x;

struct Point {
	int y = 0, x = 0;
	bool broke = false;
};

bool
	m[1000][1000];

#define NV 0 // Not Visited 
#define VB 1 // Visited with Broke 
#define VNB -1 // Visited with not Broke
int mv[1000][1000]{ 0, };

bool check(int _y, int _x, bool _broke) {
	return
		_y + 1 > 0 && _y < y&&
		_x + 1 > 0 && _x < x &&
		(_broke ?
			(!mv[_y][_x] && !m[_y][_x]) :
			(mv[_y][_x] != VNB));
}

int main(void) {
	cin >> y >> x;
	for (int _y = 0; _y < y; _y++) {
		getchar();
		for (int _x = 0; _x < x; _x++)
			m[_y][_x] = getchar() - '0';
	}
	queue<Point> ps;
	Point cp;
	int s, t(0);
	ps.push({0, 0, false});
	while (!ps.empty()) {
		s = ps.size();
		for (int _s(0); _s < s; _s++) {
			cp = ps.front(); ps.pop();
			if (cp.y + 1 == y && cp.x + 1 == x) {
				cout << t + 1;
				exit(EXIT_SUCCESS);
			}
			if (check(cp.y + 1, cp.x, cp.broke)) {
				mv[cp.y + 1][cp.x] = cp.broke ? VB : (m[cp.y + 1][cp.x] ? VB : VNB);
				ps.push({ cp.y + 1, cp.x, cp.broke ? true : m[cp.y + 1][cp.x] });
			}
			if (check(cp.y - 1, cp.x, cp.broke)) {
				mv[cp.y - 1][cp.x] = cp.broke ? VB : (m[cp.y - 1][cp.x] ? VB : VNB);
				ps.push({ cp.y - 1, cp.x, cp.broke ? true : m[cp.y - 1][cp.x] });
			}
			if (check(cp.y, cp.x + 1, cp.broke)) {
				mv[cp.y][cp.x + 1] = cp.broke ? VB : (m[cp.y][cp.x + 1] ? VB : VNB);
				ps.push({ cp.y, cp.x + 1, cp.broke ? true : m[cp.y][cp.x + 1] });
			}
			if (check(cp.y, cp.x - 1, cp.broke)) {
				mv[cp.y][cp.x - 1] = cp.broke ? VB : (m[cp.y][cp.x - 1] ? VB : VNB);
				ps.push({ cp.y, cp.x - 1 ,cp.broke ? true : m[cp.y][cp.x - 1] });
			}
		}
		t++;
	}
	cout << -1;
}