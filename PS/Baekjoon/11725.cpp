#include<iostream>
#include<vector>

using namespace std;

int n, bf, bt, nps[100'000];
vector<int> nes[100'000];

void gnp(int _f, int _n) {
	nps[_n] = _f;
	for (int _e(0); _e < nes[_n].size(); _e++)
		if (nes[_n][_e] != nps[_n])
			gnp(_n, nes[_n][_e]);
}

int main(void) {
	cin >> n;
	for (int _n(0); _n < n - 1; _n++) {
		cin >> bf >> bt;
		nes[bt - 1].push_back(bf - 1);
		nes[bf - 1].push_back(bt - 1);
	}
	gnp(0, 0);
	for (int _n(1); _n < n; _n++)
		cout << nps[_n] + 1 << '\n';
}