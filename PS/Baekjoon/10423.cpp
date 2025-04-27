#include<iostream>
#include<algorithm>

using namespace std;

struct E {
	int na, nb, w;
};

int n, m, k, bk, us[1'000 + 1], s;
E* es;
bool ks[1'000 + 1];

bool operator<(const E& _a, const E& _b) {
	return _a.w < _b.w;
}

int gu(int _n) {
	if (!us[_n]) return _n;
	return us[_n] = gu(us[_n]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int _k(0); _k < k; _k++) {
		cin >> bk; ks[bk] = true;
	}
	es = new E[m];
	for (int _m(0); _m < m; _m++)
		cin >> es[_m].na >> es[_m].nb >> es[_m].w;
	sort(es, es + m);
	for (int _m(0); _m < m; _m++)
		if (gu(es[_m].na) != gu(es[_m].nb))
			if (!ks[gu(es[_m].na)] || !ks[gu(es[_m].nb)]) {
				s += es[_m].w;
				if (ks[gu(es[_m].na)]) us[gu(es[_m].nb)] = es[_m].na;
				else if (ks[gu(es[_m].nb)]) us[gu(es[_m].na)] = es[_m].nb;
				else us[gu(es[_m].na)] = es[_m].nb;
			}
	cout << s;
	delete[] es;
}