#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct N {
	int l, r, c;
};

int n, k, kss[41];
N ns[1000];
vector<N*> nkrs[41], nkcs[41];
bool ks[41];

void dfs(int _k, bool _f) {
	if(_k == k + 1) {
		for(int _k(1); _k < k + 1; _k++)
			cout << (ks[_k] ? '#' : '-');
		exit(EXIT_SUCCESS);
	}

	ks[_k] = _f;
	kss[_k] = kss[_k - 1] + _f;

	for(int _nkc(0); _nkc < nkcs[_k].size(); _nkc++)
		if(kss[_k] - kss[nkcs[_k][_nkc]->l - 1] != nkcs[_k][_nkc]->c)
			return;
	for(int _nkr(0); _nkr < nkrs[_k].size(); _nkr++)
		if(kss[_k] - kss[nkrs[_k][_nkr]->l - 1] > nkrs[_k][_nkr]->c)
			return;

	dfs(_k + 1, true);
	dfs(_k + 1, false);
}

int main(void) {
	cin >> k >> n;
	for(int _n(0); _n < n; _n++) {
		cin >> ns[_n].l >> ns[_n].r >> ns[_n].c;
		for(int _k(ns[_n].l); _k < ns[_n].r; _k++)
			nkrs[_k].push_back(&ns[_n]);
		nkcs[ns[_n].r].push_back(&ns[_n]);
	}
	dfs(1, true);
	dfs(1, false);
	cout << "NONE";
}