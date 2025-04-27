#include<iostream>
#include<algorithm>

using namespace std;

struct N {
	int n;
	N* pn, * lcn, * rcn;

	N(const int& _n, N* _pn) : n(_n), pn(_pn), lcn(nullptr), rcn(nullptr) {}
};

int n, io[100'000], po[100'000];
N* rn;

void mt(N* _pn, int* _io, int* _po, const long long int& _s) {
	if (!_s) return;
	N* _n = (_pn->lcn == nullptr ? _pn->lcn : _pn->rcn) = new N(_po[_s - 1], _pn);
	int* m = find(_io, _io + _s, _po[_s - 1]);
	mt(_n, _io, _po, m - _io);
	mt(_n, m + 1, _po + (m - _io), _s - (m - _io) - 1);
}

void pp(const N* _n) {
	if (_n == nullptr) return;
	cout << _n->n << ' ';
	pp(_n->lcn);
	pp(_n->rcn);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> io[_n];
	for (int _n(0); _n < n; _n++)
		cin >> po[_n];
	rn = new N(po[n - 1], nullptr);
	int* m = find(io, io + n, po[n - 1]);
	mt(rn, io, po, m - io);
	mt(rn, m + 1, po + (m - io), n - (m - io) - 1);
	pp(rn);
}