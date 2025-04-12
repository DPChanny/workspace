#include<iostream>

using namespace std;

int dp[1001][1001];

int main(void) {
	int n;
	cin >> n;
	int ns[1000];

	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];

	for (int _n(1); _n < n + 1; _n++)
	{
		for (int _c(1); _c < n + 1; _c++)
		{
			if (_c < _n)
				dp[_n][_c] = dp[_n - 1][_c];
			else {
				dp[_n][_c] = dp[_n][_c - _n] + ns[_n - 1];
				if (dp[_n - 1][_c - _n])
					dp[_n][_c] = min(dp[_n][_c], dp[_n - 1][_c - _n] + ns[_n - 1]);
				if (dp[_n - 1][_c])
					dp[_n][_c] = min(dp[_n][_c], dp[_n - 1][_c]);
			}
		}
	}
	cout << dp[n][n] << endl;
}