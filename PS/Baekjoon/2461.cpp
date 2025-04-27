#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define pv first
#define pn second

int n, m, bnm, nus[1'000], c, nml, nmr, r(1'000'000'000);
vector<pair<int, int>> nms;

int main(void) {
	cin >> n >> m;
	for (int _n(0); _n < n; _n++)
		for (int _m(0); _m < m; _m++) {
			cin >> bnm;
			nms.emplace_back(bnm, _n);
		}
	sort(nms.begin(), nms.end());
	nus[nms[nml].pn]++;
	c++;
	while (true) {
		if (c == n) {
			r = min(nms[nmr].pv - nms[nml].pv, r);
			if (nmr - nml + 1 == c)
				if (nmr + 1 < n * m) nus[nms[++nmr].pn]++;
				else break;
			else if (!--nus[nms[nml++].pn]) c--;
		} else if (nmr + 1 < n * m) {
			if (!nus[nms[++nmr].pn]++) c++;
		} else break;
	}
	cout << r;
}