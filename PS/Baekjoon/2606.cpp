#include<iostream>
#include<vector>

using namespace std;

int n, k, bf, bt, c;
vector<int> cs[100];
bool vs[100];

void dfs(int _f) {
	c++;
	vs[_f] = true;
	for (int _t(0); _t < cs[_f].size(); _t++)
		if (!vs[cs[_f][_t]])
			dfs(cs[_f][_t]);
}

int main(void) {
	cin >> n >> k;
	for (int _k(0); _k < k; _k++) {
		cin >> bf >> bt;
		cs[bf - 1].push_back(bt - 1);
		cs[bt - 1].push_back(bf - 1);
	}
	dfs(0);
	cout << c - 1;
}