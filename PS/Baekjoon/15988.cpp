#include<iostream>

using namespace std;

long long int dp[1000000]{1, 2, 4};

int main(void) {
	int t, n, mn(3);
	cin >> t;
	for (int _t(0); _t < t; _t++) {
		cin >> n;
		if (n > mn) {
			for (int _n(mn); _n < n; _n++)
				dp[_n] = (dp[_n - 1] + dp[_n - 2] + dp[_n - 3]) % 1000000009;
			mn = n;
		}
		cout << dp[n - 1] << '\n';
	}
}