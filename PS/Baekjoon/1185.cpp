#include<iostream>
#include<algorithm>

using namespace std;

int n, p, ns[10'000], us[10'000 + 1], s;

class E {
public:
	int na, nb, w;

	int gv() const {
		return w * 2 + ns[na - 1] + ns[nb - 1];
	}

	bool operator<(const E& _a) {
		return gv() < _a.gv();
	}
};

E* es;

int gu(int _n) {
	if (!us[_n]) return _n;
	return us[_n] = gu(us[_n]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> p;
	es = new E[p];
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for (int _p(0); _p < p; _p++)
		cin >> es[_p].na >> es[_p].nb >> es[_p].w;
	sort(es, es + p);
	for (int _p(0); _p < p; _p++)
		if (gu(es[_p].na) != gu(es[_p].nb)) {
			us[gu(es[_p].na)] = gu(es[_p].nb);
			s += es[_p].gv();
		}
	cout << s + *min_element(ns, ns + n);
	delete[] es;
}