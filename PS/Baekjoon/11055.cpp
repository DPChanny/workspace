#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int n, ns[1000], dp[1000];
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for (int _n(0); _n < n; _n++) {
		int m(0);
		for (int i(0); i < _n; i++)
			if (ns[i] < ns[_n]) m = max(m, dp[i]);
		dp[_n] = m + ns[_n];
	}
	int m(0);
	for (int _n(0); _n < n; _n++)
		m = max(m, dp[_n]);
	cout << m;
}