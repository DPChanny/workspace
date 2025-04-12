#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long int lli;

lli n, m, mb, bf, bt, tcs[1'000], cn;
vector<lli> fts[1'000], rs;
queue<lli> ns;

int main(void) {
	cin >> n >> m;
	for (lli _m(0); _m < m; _m++) {
		cin >> mb >> bt;
		for (lli _mb(0); _mb < mb - 1; _mb++) {
			cin >> bf;
			fts[bt - 1].push_back(bf - 1);
			tcs[bf - 1]++;
			bt = bf;
		}
	}
	for (lli _n(0); _n < n; _n++)
		if (!tcs[_n]) ns.push(_n);
	while (!ns.empty()) {
		cn = ns.front(); ns.pop();
		rs.push_back(cn);
		for (lli _t(0); _t < fts[cn].size(); _t++) 
			if (!(--tcs[fts[cn][_t]]))
				ns.push(fts[cn][_t]);
	}
	if (rs.size() == n)
		for (lli _n(0); _n < n; _n++)
			cout << rs[_n] + 1 << '\n';
	else cout << 0;
}