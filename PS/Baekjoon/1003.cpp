#include<iostream>

using namespace std;

constexpr int MN = 40;

int dp[MN + 1][2], n, t;

int main(void) {
	dp[0][0] = dp[1][1] = 1;
	for (int _dp(2); _dp < MN + 1; _dp++) {
		dp[_dp][0] = dp[_dp - 1][0] + dp[_dp - 2][0];
		dp[_dp][1] = dp[_dp - 1][1] + dp[_dp - 2][1];
	}
	cin >> t;
	for (int _t(0); _t < t; _t++) {
		cin >> n;
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
	}
}