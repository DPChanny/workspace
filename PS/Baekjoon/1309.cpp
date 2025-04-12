#include<iostream>

using namespace std;

int dp[3][100000]{ {1, 1, 1}, };

int main(void) {
	int n;
	cin >> n;
	for (int _n(1); _n < n + 1; _n++) {
		dp[0][_n] = (dp[0][_n - 1] + dp[1][_n - 1] + dp[2][_n - 1]) % 9901;
		dp[1][_n] = (dp[0][_n - 1] + dp[2][_n - 1]) % 9901;
		dp[2][_n] = (dp[0][_n - 1] + dp[1][_n - 1]) % 9901;
	}
	cout << (dp[0][n] + dp[1][n] + dp[2][n]) % 9901;
}