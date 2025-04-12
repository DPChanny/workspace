#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long int nss[100'000 + 1], m;

int main(void) {
	cin >> n;
	for (int _n(1); _n < n + 1; _n++) {
		cin >> nss[_n];
		nss[_n] += nss[_n - 1];
	}
	for (int _i(1 + 1); _i < n + 1 - 1; _i++)
		m = max(m, nss[_i - 1] - nss[1] + (nss[n] - nss[_i]) * 2);
	for (int _i(1 + 1); _i < n + 1 - 1; _i++)
		m = max(m, nss[_i - 1] * 2 + nss[n - 1] - nss[_i]);
	for (int _i(1 + 1); _i < n + 1 - 1; _i++)
		m = max(m, nss[_i] - nss[1] + nss[n - 1] - nss[_i - 1]);
	cout << m;
}