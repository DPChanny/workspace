#include<iostream>
#include<cstring>

using namespace std;

struct N {
	int a, b, c, d, e;
};
N operator+(const N& _a, const N& _b) {
	return { _a.a + _b.a, _a.b + _b.b, _a.c + _b.c, _a.d + _b.d, _a.e + _b.e };
}
N operator-(const N& _a, const N& _b) {
	return { _a.a - _b.a, _a.b - _b.b, _a.c - _b.c, _a.d - _b.d, _a.e - _b.e };
}
bool operator>(const N& _a, const N& _b) {
	return _a.a + 1 > _b.a && _a.b + 1 > _b.b && _a.c + 1 > _b.c && _a.d + 1 > _b.d;
}

int n, m;
N t, c, ns[15];
bool nus[15], mnus[15];

bool ck(const N& _a) {
	return _a.a || _a.b || _a.c || _a.d || _a.e;
}

void gm(int _n, bool _s) {
	if(_n == n) {
		if(c > t && c.e < m) {
			memcpy(mnus, nus, sizeof(mnus));
			m = c.e;
		}
		return;
	}
	if(ck(ns[_n])) {
		if(_s) c = c + ns[_n];
		nus[_n] = _s;
		gm(_n + 1, true);
	}
	gm(_n + 1, false);
	if(ck(ns[_n])) {
		if(_s) c = c - ns[_n];
		nus[_n] = false;
	}
}

int main(void) {
	m = 1'000'000;
	cin >> n >> t.a >> t.b >> t.c >> t.d;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n].a >> ns[_n].b >> ns[_n].c >> ns[_n].d >> ns[_n].e;
	gm(0, true);
	gm(0, false);
	if(m == 1'000'000) cout << -1;
	else {
		cout << m << '\n';
		for(int _n(0); _n < n; _n++)
			if(mnus[_n]) cout << _n + 1 << ' ';
	}
}