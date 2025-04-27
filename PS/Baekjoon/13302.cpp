#include<iostream>

constexpr int INF = 1'000'000'000;
constexpr int K = 40;

using namespace std;

int n, m, bm, ns[101][41];
bool ms[101];

int main(void) {
	cin >> n >> m;
	for(int _m(0); _m < m; _m++) {
		cin >> bm;
		ms[bm] = true;
	}
	for(int _n(0); _n < n + 1; _n++)
		for(int _k(0); _k < K + 1; _k++)
			ns[_n][_k] = INF;
	ns[0][0] = 0;
	for(int _n(1); _n < n + 1; _n++) {
		for(int _k(0); _k < K + 1; _k++) {
			if(ms[_n]) ns[_n][_k] = ns[_n - 1][_k];
			if(ns[_n - 1][_k] != INF)
				ns[_n][_k] = min(ns[_n][_k], ns[_n - 1][_k] + 10'000);
			if(_k + 3 < K + 1)
				if(ns[_n - 1][_k + 3] != INF)
					ns[_n][_k] = min(ns[_n][_k], ns[_n - 1][_k + 3]);
			if(_n > 2 && _k > 0)
				if(ns[_n - 3][_k - 1] != INF)
					ns[_n][_k] = min(ns[_n][_k], ns[_n - 3][_k - 1] + 25'000);
			if(_n > 4 && _k > 1)
				if(ns[_n - 5][_k - 2] != INF)
					ns[_n][_k] = min(ns[_n][_k], ns[_n - 5][_k - 2] + 37'000);
		}
	}
	int c(ns[n][0]);
	for(int _k(1); _k < K + 1; _k++)
		c = min(c, ns[n][_k]);
	cout << c;
}