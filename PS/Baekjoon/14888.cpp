#include<iostream>

using namespace std;

int n, ns[11], a, b, c, d, h(-1'000'000'000), l(1'000'000'000);

void ghl(int _a, int _b, int _c, int _d, int _n, int _t) {
	if(_n == n) {
		h = max(_t, h);
		l = min(_t, l);
		return;
	}
	if(_a < a) ghl(_a + 1, _b, _c, _d, _n + 1, _t + ns[_n]);
	if(_b < b) ghl(_a, _b + 1, _c, _d, _n + 1, _t - ns[_n]);
	if(_c < c) ghl(_a, _b, _c + 1, _d, _n + 1, _t * ns[_n]);
	if(_d < d) ghl(_a, _b, _c, _d + 1, _n + 1, _t / ns[_n]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	cin >> a >> b >> c >> d;
	if(a) ghl(1, 0, 0, 0, 2, ns[0] + ns[1]);
	if(b) ghl(0, 1, 0, 0, 2, ns[0] - ns[1]);
	if(c) ghl(0, 0, 1, 0, 2, ns[0] * ns[1]);
	if(d) ghl(0, 0, 0, 1, 2, ns[0] / ns[1]);
	cout << h << '\n' << l;
}