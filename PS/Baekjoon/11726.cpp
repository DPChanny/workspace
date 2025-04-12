#include<iostream>

using namespace std;

int n, dp[1000]{ 1, 2, };

int main(void) {
	cin >> n;
	for(int _n(2); _n < n; _n++)
		dp[_n] = (dp[_n - 1] + dp[_n - 2]) % 10007;
	cout << dp[n - 1];
}