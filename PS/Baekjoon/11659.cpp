#include<iostream>

using namespace std;

int n, m, ns[100'000 + 1], bf, bt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int _n(1); _n < n + 1; _n++) {
		cin >> ns[_n];
		ns[_n] += ns[_n - 1];
	}
	for (int _m(0); _m < m; _m++) {
		cin >> bf >> bt;
		cout << ns[bt] - ns[bf - 1] << '\n';
	}
}