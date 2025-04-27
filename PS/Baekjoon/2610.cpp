#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> R;

bool operator<(R _a, R _b) {
	if (_a.first == _b.first) return _a.second < _b.second;
	return _a.first < _b.first;
}

lli n, m, bf, bt, us[100 + 1];
vector<R> rs(100 + 1, { INT64_MAX, 0 });
priority_queue<lli, vector<lli>, greater<lli>> rns;
vector<lli> es[100 + 1];

lli gu(lli _n) {
	if (!us[_n]) return _n;
	return us[_n] = gu(us[_n]);
}

lli gr(lli _n) {
	vector<bool> nvs(100 + 1, false);
	queue<lli> ns;
	nvs[_n] = true;
	ns.push(_n);
	lli _r(0), cn, nss;
	while (!ns.empty()) {
		nss = ns.size();
		for (lli _ns(0); _ns < nss; _ns++) {
			cn = ns.front(); ns.pop();
			for (lli _e(0); _e < es[cn].size(); _e++)
				if (!nvs[es[cn][_e]]) {
					ns.push(es[cn][_e]);
					nvs[es[cn][_e]] = true;
				}
		}
		_r++;
	}
	return _r - 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (lli _m(0); _m < m; _m++) {
		cin >> bf >> bt;
		if (gu(bf) != gu(bt)) us[gu(bf)] = gu(bt);
		es[bf].push_back(bt);
		es[bt].push_back(bf);
	}
	for (lli _n(1); _n < n + 1; _n++)
		rs[gu(_n)] = min(rs[gu(_n)], { gr(_n),_n });
	for (lli _u(1); _u < 100 + 1; _u++)
		if (rs[_u].first != INT64_MAX) rns.push(rs[_u].second);
	cout << rns.size() << '\n';
	while (!rns.empty()) {
		cout << rns.top() << '\n'; rns.pop();
	}
}