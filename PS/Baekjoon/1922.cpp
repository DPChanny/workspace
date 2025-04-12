#include<iostream>
#include<algorithm>

using namespace std;

struct E {
	int na, nb, w;
};

int n, m, us[1000 + 1], s;
E* es;

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
	cin >> n >> m;
	es = new E[m];
	for (int _m(0); _m < m; _m++)
		cin >> es[_m].na >> es[_m].nb >> es[_m].w;
	sort(es, es + m);
	for (int _m(0); _m < m; _m++) 
		if (gu(es[_m].na) != gu(es[_m].nb)) {
			s += es[_m].w;
			us[gu(es[_m].na)] = es[_m].nb;
		}
	cout << s;
	delete[] es;
}