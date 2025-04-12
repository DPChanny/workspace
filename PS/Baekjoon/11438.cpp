#include<iostream>
#include<vector>

constexpr int MAX_ST(20);

using namespace std;

int n, m, ba, bb, st[MAX_ST][100'000], ds[100'000];
vector<int> es[100'000];

void gst(const int& _n, const int& _p, const int& _d) {
	ds[_n] = _d; st[0][_n] = _p;
	for (int _e(0); _e < es[_n].size(); _e++)
		if (st[0][_n] != es[_n][_e])
			gst(es[_n][_e], _n, _d + 1);
}

int glca(int _a, int _b) {
	if (ds[_a] > ds[_b]) {
		int t = _a;
		_a = _b; _b = t;
	}
	for (int i(MAX_ST - 1); i + 1 > 0; i--)
		if (ds[_b] - ds[_a] + 1 > 1 << i)
			_b = st[i][_b];
	if (_a == _b) return _a;
	for (int i(MAX_ST - 1); i + 1 > 0; i--)
		if (st[i][_a] != st[i][_b]) {
			_a = st[i][_a];
			_b = st[i][_b];
		}
	return st[0][_a];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int _n(0); _n < n - 1; _n++) {
		cin >> ba >> bb;
		es[ba - 1].push_back(bb - 1);
		es[bb - 1].push_back(ba - 1);
	}
	gst(0, 0, 0);
	for (int i(1); i < MAX_ST; i++)
		for (int _n(0); _n < n; _n++)
			st[i][_n] = st[i - 1][st[i - 1][_n]];
	cin >> m;
	for (int _m(0); _m < m; _m++) {
		cin >> ba >> bb;
		cout << glca(ba - 1, bb - 1) + 1 << '\n';
	}
}