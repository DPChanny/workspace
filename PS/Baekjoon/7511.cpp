#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> ns[1'000'000];
bool nvs[1'000'000];
int ngs[1'000'000], n, m, bf, bt, g, t, k;

void dfs(int _f, int _g) {
	nvs[_f] = true;
	ngs[_f] = _g;
	for(int _t(0); _t < ns[_f].size(); _t++)
		if(!nvs[ns[_f][_t]]) dfs(ns[_f][_t], _g);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for(int _t(0); _t < t; _t++) {
		cout << "Scenario " << _t + 1 << ":\n";
		cin >> n >> k;
		memset(nvs, false, sizeof(bool) * n);
		for(int _n(0); _n < n; _n++)
			ns[_n].clear();
		g = 0;
		for(int _k(0); _k < k; _k++) {
			cin >> bf >> bt;
			ns[bf].push_back(bt);
			ns[bt].push_back(bf);
		}
		for(int _n(0); _n < n; _n++)
			if(!nvs[_n]) dfs(_n, g++);
		cin >> m;
		for(int _m(0); _m < m; _m++) {
			cin >> bf >> bt;
			cout << (ngs[bf] == ngs[bt] ? 1 : 0) << '\n';
		}
		cout << '\n';
	}
}