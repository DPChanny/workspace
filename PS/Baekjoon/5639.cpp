#include<iostream>

using namespace std;

struct N {
	int n;
	N* pn, * lcn, * rcn;

	N(const int& _n, N* _pn) : n(_n), pn(_pn), lcn(nullptr), rcn(nullptr) {}
};

int n, po[10'000];
N* rn;

void mt(N* _pn, int* _po, const long long int& _s) {
	if (!_s) return;
	N* _n = (_pn->lcn == nullptr ? _pn->lcn : _pn->rcn) = new N(_po[0], _pn);
	int* m(_po + 1);
	while (m - _po < _s && *m < _po[0]) m++;
	mt(_n, _po + 1, m - _po - 1);
	mt(_n, m, _s - (m - _po));
}

void pp(const N* _n) {
	if (_n == nullptr) return;
	pp(_n->lcn);
	pp(_n->rcn);
	cout << _n->n << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while (!cin.eof())
		cin >> po[n++];
	n--;
	rn = new N(po[0], nullptr);
	int* m(po + 1);
	while (m - po < n && *m < po[0]) m++;
	mt(rn, po + 1, m - po - 1);
	mt(rn, m, n - (m - po));
	pp(rn);
}