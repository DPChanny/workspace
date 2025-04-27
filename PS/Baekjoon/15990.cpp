#include<iostream>
#include<algorithm>

using namespace std;

long long int dp[100001][3]{ {0, 0, 0}, {1, 0, 0 }, {0, 1, 0}, {1, 1, 1}, };

int main(void) {
	int n, t;
	cin >> t;
	for (int _t(0); _t < t; _t++)
	{
		cin >> n;
		for (int _n(4); _n < n + 1; _n++) {

			dp[_n][0] = (dp[_n - 1][1] + dp[_n - 1][2]) % 1000000009;
			dp[_n][1] = (dp[_n - 2][0] + dp[_n - 2][2]) % 1000000009;
			dp[_n][2] = (dp[_n - 3][0] + dp[_n - 3][1]) % 1000000009;
		}
		cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 1000000009 << '\n';
	}
}