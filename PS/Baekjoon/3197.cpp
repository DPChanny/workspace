#include<iostream>
#include<queue>

using namespace std;

typedef long long int  lli;
typedef pair<lli, lli> P;
#define pf first
#define ps second
P operator+(P _a, P _b) {
	return { _a.pf + _b.pf, _a.ps + _b.ps };
}

constexpr lli YXM = 1500;

lli y, x, r;
char yxs[YXM][YXM];
bool wvs[YXM][YXM], lvs[YXM][YXM];
const vector<P> vs = { {0, 1},{0, -1},{1, 0},{-1,0 } };
queue<P> ews, els;


bool cp(P _p) {
	return
		_p.pf + 1 > 0 && _p.pf < y&&
		_p.ps + 1 > 0 && _p.ps < x;
}

void gews() {
	queue<P> tews = ews;
	ews = queue<P>();
	P cew, np;
	while (!tews.empty()) {
		cew = tews.front(); tews.pop();
		if (yxs[cew.pf][cew.ps] != 'L') yxs[cew.pf][cew.ps] = '.';
		for (lli _v(0); _v < vs.size(); _v++) {
			np = cew + vs[_v];
			if (cp(np) && !wvs[np.pf][np.ps]) {
				wvs[np.pf][np.ps] = true;
				if (yxs[np.pf][np.ps] != 'X') tews.push(np);
				else ews.push(np);
			}
		}
	}
}

bool gels() {
	bool f(false);
	queue<P> tels = els;
	els = queue<P>();
	P cel, np;
	while (!tels.empty()) {
		cel = tels.front(); tels.pop();
		if (yxs[cel.pf][cel.ps] != 'L') yxs[cel.pf][cel.ps] = '.';
		for (lli _v(0); _v < vs.size(); _v++) {
			np = cel + vs[_v];
			if (cp(np) && !lvs[np.pf][np.ps]) {
				lvs[np.pf][np.ps] = true;
				if (yxs[np.pf][np.ps] == 'L') f = true;
				if (yxs[np.pf][np.ps] != 'X') tels.push(np);
				else els.push(np);
			}
		}
	}
	return f;
}

int main(void) {
	cin >> y >> x;
	for (lli _y(0); _y < y; _y++)
		for (lli _x(0); _x < x; _x++)
			cin >> yxs[_y][_x];
	for (lli _y(0); _y < y; _y++)
		for (lli _x(0); _x < x; _x++) {
			if (els.empty() && yxs[_y][_x] == 'L' && !lvs[_y][_x]) {
				lvs[_y][_x] = true;
				els.push({ _y, _x });
			}
			if ((yxs[_y][_x] == '.' || yxs[_y][_x] == 'L') && !wvs[_y][_x]) {
				wvs[_y][_x] = true;
				ews.push({ _y, _x });
			}
		}
	while (true) {
		gews();
		if (gels()) {
			cout << r;
			break;
		}
		r++;
	}
}