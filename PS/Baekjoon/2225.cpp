#include <iostream>

using namespace std;

long long int dp[201][201]{ };

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int _n(0); _n < n + 1; _n++) {
		dp[0][_n] = 1;
		for (int _k(1); _k < k; _k++) {
			for (int i(0); i < _n + 1; i++)
				dp[_k][_n] += dp[_k - 1][i];
			dp[_k][_n] %= 1000000000;
			if (dp[_k][_n])
				dp[_k][_n]++;
		}
	}
	cout << dp[k - 1][n - 1];
}