#include<iostream>
#include<vector>

using namespace std;

struct N {
	int p, d;
	vector<int> cs;
};

int t, n, b1, b2;
N npds[10'000 + 1];

void gnds(int _n) {
	npds[_n].d = npds[npds[_n].p].d + 1;
	for (int _c(0); _c < npds[_n].cs.size(); _c++)
		gnds(npds[_n].cs[_c]);
}

int gcp(int _a, int _b) {
	while (npds[_a].d != npds[_b].d)
		(npds[_a].d < npds[_b].d ? _b : _a) = npds[(npds[_a].d < npds[_b].d ? _b : _a)].p;
	while (npds[_a].p != npds[_b].p) {
		_a = npds[_a].p;
		_b = npds[_b].p;
	}
	return _a != _b ? npds[_a].p : _a;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	for (int _t(0); _t < t; _t++) {
		cin >> n;
		for (int _n(0); _n < n - 1; _n++) {
			cin >> b1 >> b2;
			npds[b2].p = b1;
			npds[b1].cs.push_back(b2);
		}
		while (npds[b1].p) b1 = npds[b1].p;
		gnds(b1);
		cin >> b1 >> b2;
		cout << gcp(b1, b2) << '\n';
		for (int _n(1); _n < n + 1; _n++) {
			npds[_n].cs.clear();
			npds[_n].p = npds[_n].d = 0;
		}
	}
}