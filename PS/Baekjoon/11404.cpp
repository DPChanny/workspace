#include<iostream>

using namespace std;

constexpr long long int INF = 1'000'000'000'000;

int n, m, bf, bt;
long long int ds[100][100], bw;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int _f(0); _f < n; _f++)
		for(int _t(0); _t < n; _t++)
			ds[_f][_t] = INF * (_f != _t);
	for(int _m(0); _m < m; _m++) {
		cin >> bf >> bt >> bw; 
		ds[bf - 1][bt - 1] = min(ds[bf - 1][bt - 1], bw);
	}
	for(int _k(0); _k < n; _k++)
		for(int _f(0); _f < n; _f++)
			for(int _t(0); _t < n; _t++)
				ds[_f][_t] = min(ds[_f][_t], ds[_f][_k] + ds[_k][_t]);
	for(int _f(0); _f < n; _f++) {
		for(int _t(0); _t < n; _t++)
			cout << (ds[_f][_t] != INF) * ds[_f][_t] << ' ';
		cout << '\n';
	}
}