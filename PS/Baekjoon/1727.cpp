#include<iostream>
#include<algorithm>

using namespace std;

int n, m, nmgs[1000][1000], ns[1000], ms[1000], cm;

int main(void) {
	cin >> n >> m;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for(int _m(0); _m < m; _m++)
		cin >> ms[_m];
	sort(ns, ns + n); sort(ms, ms + m);
	if(n < m) {
		swap(ns, ms);
		swap(n, m);
	}
	for(int _n(0); _n < n; _n++)
		for(int _m(0); _m < m; _m++)
			nmgs[_n][_m] = abs(ns[_n] - ms[_m]);
	for(int _m(1); _m < m; _m++) {
		cm = 1e9;
		for(int _n(_m); _n < n; _n++) {
			nmgs[_n][_m] += min(nmgs[_n - 1][_m - 1], cm);
			cm = min(nmgs[_n - 1][_m - 1], cm);
		}
	}
	cm = 1e9;
	for(int _n(m - 1); _n < n; _n++)
		cm = min(cm, nmgs[_n][m - 1]);
	cout << cm;
}
