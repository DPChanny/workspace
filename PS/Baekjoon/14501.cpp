#include<iostream>

using namespace std;

constexpr int T = 0;
constexpr int P = 1;

int main(void) {
	int n, ns[16][2], dp[15]{};
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n][T] >> ns[_n][P];
	for (int _n(0); _n < n + 1; _n++)
	{
		for (int i(0); i < _n; i++)
		{
			dp[_n] = max(dp[i], dp[_n]);
			if (i + ns[i][T] == _n)
				dp[_n] = max(dp[i] + ns[i][P], dp[_n]);
		}
	}
	cout << dp[n];
}