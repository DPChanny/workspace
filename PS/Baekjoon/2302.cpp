#include<iostream>

using namespace std;

constexpr int N = 40;

int dp[N + 1]{ 1, 1 }, n, m, bm, lm, c(1);

int main(void) {
	for(int _dp(2); _dp < N + 1; _dp++)
		dp[_dp] = dp[_dp - 1] + dp[_dp - 2];
	cin >> n >> m;
	for(int _m(0); _m < m; _m++) {
		cin >> bm;
		c *= dp[bm - lm - 1];
		lm = bm;
	}
	c *= dp[n - lm];
	cout << c;
}