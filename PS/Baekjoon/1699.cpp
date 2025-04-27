#include<iostream>

using namespace std;

int dp[100001];

int main(void) {
	int n;
	cin >> n;
	for (int i(1); i < 100001; i++)
		dp[i] = INT_MAX;
	for (int i(1); i < n + 1; i++)
		for (int j(1); j * j < i + 1; j++)
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
	cout << dp[n];
}