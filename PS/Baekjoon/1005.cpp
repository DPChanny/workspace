#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

uint16_t n, w, bf, bt;
vector<uint16_t> ks[1000];
uint32_t t, k, ns[1000];
uint64_t dp[1000];
bool vs[1000];

uint64_t dfs(uint16_t _n) {
	if(!vs[_n]) {
		vs[_n] = true;
		if(ks[_n].empty()) dp[_n] = ns[_n];
		else {
			uint64_t m(0);
			for(uint32_t _k(0); _k < ks[_n].size(); _k++)
				m = max(m, dfs(ks[_n][_k]));
			dp[_n] = m + ns[_n];
		}
	}
	return dp[_n];
}

int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for(uint32_t _t(0); _t < t; _t++) {
		cin >> n >> k;
		for(uint16_t _n(0); _n < n; _n++)
			cin >> ns[_n];
		for(uint32_t _k(0); _k < k; _k++) {
			cin >> bf >> bt;
			ks[bt - 1].push_back(bf - 1);
		}
		cin >> w;
		cout << dfs(w - 1) << '\n';
		memset(vs, false, sizeof(bool) * n);
		for(uint16_t _n(0); _n < n; _n++)
			ks[_n].clear();
	}
}
