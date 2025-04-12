#include<iostream>
#include<algorithm>

using namespace std;

struct N {
	int v;
	int g;
	bool k;
};

bool cv(const N& _a, const N& _b) {
	return _a.v < _b.v;
}

bool cg(const N& _a, const N& _b) {
	return _a.g > _b.g;
}

N ns[10000];

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n].v;
	sort(ns, ns + n, cv);
	for (int _n(1); _n < n; _n++)
		ns[_n].g = ns[_n].v - ns[_n - 1].v;
	sort(ns, ns + n, cg);
	for (int _k(0); _k < k - 1; _k++)
		ns[_k].k = true;
	sort(ns, ns + n, cv);
	int s(0);
	for (int _n(0); _n < n; _n++)
		while(_n < n && !ns[_n].k)
			s += ns[_n++].g;
	cout << s;
}