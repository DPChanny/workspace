#include<iostream>
#include<queue>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> P;
#define pf first
#define ps second
P operator+(P _a, P _b) {
	return { _a.pf + _b.pf, _a.ps + _b.ps };
}

class N {
public:
	P p;
	lli k;

	N(P _p, lli _k) : p(_p), k(_k) {}

	N() : p({ 0, 0 }), k(0) {

	}
};

lli y, x, k, nss, r;
bool yxs[1'000][1'000], yxvs[11][1'000][1'000], f;
queue<N> ns;
N cn, nn;
vector<P> vs({ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } });

bool cp(P _p) {
	return
		_p.pf + 1 > 0 && _p.pf < y&&
		_p.ps + 1 > 0 && _p.ps < x;
}

int main(void) {
	cin >> y >> x >> k;
	for (lli _y(0); _y < y; _y++) {
		getchar();
		for (lli _x(0); _x < x; _x++)
			yxs[_y][_x] = getchar() - '0';
	}
	ns.push(N());
	while (!ns.empty()) {
		nss = ns.size();
		for (lli _ns(0); _ns < nss; _ns++) {
			f = false;
			cn = ns.front(); ns.pop();
			if (cn.p.pf == y - 1 && cn.p.ps == x - 1) {
				cout << r + 1;
				exit(EXIT_SUCCESS);
			}
			for (lli _v(0); _v < vs.size(); _v++) {
				nn = N(cn.p + vs[_v], cn.k);
				if (cp(nn.p)) {
					if (r % 2 && yxs[nn.p.pf][nn.p.ps]) {
						f = true;
						continue;
					}
					if (nn.k + yxs[nn.p.pf][nn.p.ps] < k + 1 && !yxvs[nn.k + yxs[nn.p.pf][nn.p.ps]][nn.p.pf][nn.p.ps]) {
						yxvs[nn.k + yxs[nn.p.pf][nn.p.ps]][nn.p.pf][nn.p.ps] = true;
						ns.push(N(nn.p, nn.k + yxs[nn.p.pf][nn.p.ps]));
					}
				}
			}if (f) ns.push(cn);
		}
		r++;
	}
	cout << -1;
}