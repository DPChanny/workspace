#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define y first
#define x second
typedef pair<int, int> point;
point operator+(const point& _a, const point& _b) {
	return { _a.y + _b.y, _a.x + _b.x };
}

constexpr int DC = 4;
point ds[DC] = { {1, 0}, {-1, 0 }, {0, 1}, {0, -1} };

int n, m, bfx, bfy, btx, bty;
vector<point> ms[100][100];
bool ns[100][100]{ true, }, vs[100][100]{ true, };

bool rc(const point& _p) {
	return
		_p.y + 1 > 0 && _p.y < n&&
		_p.x + 1 > 0 && _p.x < n;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int _m(0); _m < m; _m++) {
		cin >> bfx >> bfy >> btx >> bty;
		ms[bfy - 1][bfx - 1].push_back({ bty - 1, btx - 1 });
	}

	queue<point> eps, ps;
	point cp, np;
	bool ef(false), mf(true);
	eps.push({ 0, 0 });
	while(mf) {
		mf = false;
		ps = eps;
		eps = queue<point>();
		while(!ps.empty()) {
			cp = ps.front(); ps.pop();

			vector<point>& cms = ms[cp.y][cp.x];
			for(int _m(0); _m < cms.size(); _m++)
				ns[cms[_m].y][cms[_m].x] = true;
			cms.clear();

			for(int _d(0); _d < DC; _d++) {
				np = cp + ds[_d];
				if(rc(np)) {
					if(ns[np.y][np.x]) {
						if(!vs[np.y][np.x]) {
							vs[np.y][np.x] = true;
							ps.push(np);
							mf = true;
						}
					} else ef = true;
				}
			}
			if(ef) eps.push(cp);
			ef = false;
		}
	}

	int c(0);
	for (int _y(0); _y < n; _y++)
		for (int _x(0); _x < n; _x++)
			if (ns[_y][_x]) c++;
	cout << c;
}