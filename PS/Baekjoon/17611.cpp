#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long int lli;

#define P pair<lli, lli>
#define ps first
#define pe second

bool operator<(P& _a, P& _b) {
	if (_a.ps == _b.ps) return _a.pe < _b.pe;
	return _a.ps > _b.ps;
}

vector<P> xs, ys;
lli n, xb, yb, xa, ya, xo, yo;

lli goc(vector<P> &_ns) {
	priority_queue<lli, vector<lli>, greater<lli>> es;
	sort(_ns.begin(), _ns.end());
	lli s(_ns[0].ps), m(0);
	es.push(_ns[0].pe);
	for (lli _n(1); _n < _ns.size(); _n++) {
		s = _ns[_n].ps;
		es.push(_ns[_n].pe);
		while (es.top() < s + 1) es.pop();
		m = max(m, (lli)es.size());
	}
	return m;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> xo >> yo;
	xa = xo; ya = yo;
	for (lli _n(1); _n < n; _n++) {
		xb = xa;
		yb = ya;
		cin >> xa >> ya;
		if (!(xa - xb)) ys.emplace_back(min(ya, yb), max(ya, yb));
		if (!(ya - yb)) xs.emplace_back(min(xa, xb), max(xa, xb));
	}
	if (!(xa - xo)) ys.emplace_back(min(ya, yo), max(ya, yo));
	if (!(ya - yo)) xs.emplace_back(min(xa, xo), max(xa, xo));
	cout << max(goc(xs), goc(ys));
}