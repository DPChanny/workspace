#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define s(x, f, t) (x[(t)] - x[(f) - 1])

long long int t, n, m, ns[1'000 + 1], ms[1'000 + 1], c;
vector<long long int> nss;

int main(void) {
	cin >> t >> n;
	for (long long int _n(1); _n < n + 1; _n++) {
		cin >> ns[_n];
		ns[_n] += ns[_n - 1];
	}
	cin >> m;
	for (long long int _m(1); _m < m + 1; _m++) {
		cin >> ms[_m];
		ms[_m] += ms[_m - 1];
	}
	for (long long int _nl(1); _nl < n + 1; _nl++)
		for (long long int _nr(_nl); _nr < n + 1; _nr++)
			nss.push_back(s(ns, _nl, _nr));
	sort(nss.begin(), nss.end());
	for (long long int _ml(1); _ml < m + 1; _ml++)
		for (long long int _mr(_ml); _mr < m + 1; _mr++)
			if (binary_search(nss.begin(), nss.end(), t - s(ms, _ml, _mr)))
				c += upper_bound(nss.begin(), nss.end(), t - s(ms, _ml, _mr)) - lower_bound(nss.begin(), nss.end(), t - s(ms, _ml, _mr));
	cout << c;
}