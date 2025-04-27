#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> P;
#define pf first
#define ps second

P operator+(P _a, P _b) {
	return { _a.pf + _b.pf, _a.ps + _b.ps };
}

constexpr lli E = 0;
constexpr lli W = 1;
constexpr lli G = 2;

struct N {
	P p = { 0, 0 };
	bool g = false;
};

lli y, x, t, yxs[100][100], nss, _t;
bool yxvs[2][100][100];
queue<N> ns;
vector<P> vs({ {1, 0}, {0, 1}, {-1, 0}, {0, -1} });
N cn, nn;

bool cp(P _p) {
	return _p.pf + 1 > 0 && _p.pf < y&& _p.ps + 1 > 0 && _p.ps < x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> y >> x >> t;
	for (lli _y(0); _y < y; _y++)
		for (lli _x(0); _x < x; _x++)
			cin >> yxs[_y][_x];
	ns.push({ {0, 0} ,  false });
	while (!ns.empty() && _t < t + 1) {
		nss = ns.size();
		for (lli _ns(0); _ns < nss; _ns++) {
			cn = ns.front(); ns.pop();
			if (cn.p.pf == y - 1 && cn.p.ps == x - 1) {
				cout << _t;
				exit(EXIT_SUCCESS);
			}
			for (lli _v(0); _v < vs.size(); _v++) {
				nn = { cn.p + vs[_v], cn.g };
				if (cp(nn.p) && !yxvs[nn.g][nn.p.pf][nn.p.ps] && (nn.g || yxs[nn.p.pf][nn.p.ps] != W)) {
					yxvs[nn.g][nn.p.pf][nn.p.ps] = true;
					ns.push({ nn.p, nn.g || yxs[nn.p.pf][nn.p.ps] == G });
				}
			}
		}
		_t++;
	}
	cout << "Fail";
}