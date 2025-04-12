#include<iostream>
#include<numeric>

using namespace std;

typedef long long int lli;

lli n, ns[13], r;
bool rs[26'000'000 + 1];

void grs(lli _n, lli _m, lli _s) {
	if (_n == n) {
		if (_s > 0) rs[_s] = true;
		return;
	}
	grs(_n + 1, 0, _s + ns[_n] * _m);
	grs(_n + 1, 1, _s + ns[_n] * _m);
	grs(_n + 1, -1, _s + ns[_n] * _m);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (lli _n(0); _n < n; _n++)
		cin >> ns[_n];
	grs(0, 0, 0);
	grs(0, 1, 0);
	grs(0, -1, 0);
	for (lli _i(1); _i < accumulate(ns, ns + n, 0LL) + 1; _i++)
		if (!rs[_i]) r++;
	cout << r;
}