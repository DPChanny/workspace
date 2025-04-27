#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int lli;

lli t, n, nps[1'000], nis[1'000];

void pr(lli _npl, lli _npr, lli _nil, lli _nir) {
	if (_npr == _npl) return;
	lli l = (find(nis + _nil, nis + _nir, nps[_npl]) - nis) - _nil;
	pr(_npl + 1, _npl + l + 1, _nil, _nil + l);
	pr(_npl + l + 1, _npr, _nil + l + 1, _nir);
	cout << nps[_npl] << ' ';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	for (lli _t(0); _t < t; _t++) {
		cin >> n;
		for (lli _n(0); _n < n; _n++) cin >> nps[_n];
		for (lli _n(0); _n < n; _n++) cin >> nis[_n];
		pr(0, n, 0, n);
		cout << '\n';
	}
}