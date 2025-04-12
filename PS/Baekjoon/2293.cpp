#include<iostream>

using namespace std;

int n, k, ns[100], dp[10'000 + 1]{ 1, 0 };

int main(void) {
	cin >> n >> k;
	for (int _n(0); _n < n; _n++) {
		cin >> ns[_n];
		for (int _k(ns[_n]); _k < k + 1; _k++)
			dp[_k] = dp[_k] + dp[_k - ns[_n]];
	}
	cout << dp[k];
}