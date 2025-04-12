#include<iostream>
#include<vector>

using namespace std;

int n, bf, bt, ns[10'000], dps[10'000][2];
vector<int> es[10'000];

int dp(int _p, int _n, bool _g) {
	if (!dps[_n][_g]) {
		dps[_n][true] = ns[_n];
		for (int _t(0); _t < es[_n].size(); _t++)
			if (es[_n][_t] != _p) {
				dps[_n][true] += dp(_n, es[_n][_t], false);
				dps[_n][false] += max(dp(_n, es[_n][_t], true), dp(_n, es[_n][_t], false));
			}
	}
	return dps[_n][_g];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for (int _n(0); _n < n - 1; _n++) {
		cin >> bf >> bt;
		es[bf - 1].push_back(bt - 1);
		es[bt - 1].push_back(bf - 1);
	}
	cout << max(dp(-1, 0, false), dp(-1, 0, true));
}