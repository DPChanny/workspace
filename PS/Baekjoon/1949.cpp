#include<iostream>
#include<vector>

using namespace std;

int n, bf, bt, ns[10'000], dps[10'000];
vector<int> es[10'000];

int gdp(int _p, int _f, int _n);
int dp(int _n, int _p);

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
	cout << dp(0, -1);
}

int gdp(int _p, int _f, int _n) {
	if (!_n) return dp(_f, _p);
	int s(0);
	for (int _t(0); _t < es[_f].size(); _t++)
		if (es[_f][_t] != _p)
			s += gdp(_f, es[_f][_t], _n - 1);
	return s;
}

int dp(int _n, int _p) {
	if (!dps[_n]) 
		dps[_n] = max(gdp(_p, _n, 2) + ns[_n], gdp(_p, _n, 1));
	return dps[_n];
}