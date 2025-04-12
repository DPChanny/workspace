#include<iostream>

using namespace std;

int dp[1001][1001] = { { 0, }, };

int main(void) {
	int n;
	cin >> n;
	int ns[1000];
	for (int _n = 0; _n < n; _n++)
		cin >> ns[_n];

	for (int _n(1); _n < n + 1; _n++)
	{
		for (int _c(1); _c < n + 1; _c++)
		{
			if (_c < _n) {
				dp[_n][_c] = dp[_n - 1][_c];
				continue;
			}
			int max = dp[_n - 1][_c];
			for (int _m = 1; _m < _c / _n + 1; _m++)
				if (max < dp[_n - 1][_c - _n * _m] + _m * ns[_n - 1])
					max = dp[_n - 1][_c - _n * _m] + _m * ns[_n - 1];
			dp[_n][_c] = max;
		}
	}

	cout << dp[n][n] << endl;
}