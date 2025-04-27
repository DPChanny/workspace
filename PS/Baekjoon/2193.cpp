#include<iostream>

using namespace std;

long long int dp[90][2];

long long int g(int _n, int _ll) {
	if (!_n) return 1;
	if (!dp[_n - 1][_ll - 1]) {
		long long int s = g(_n - 1, 0);
		if (!_ll) s += g(_n - 1, 1);
		dp[_n - 1][_ll - 1] = s;
	}
	return dp[_n - 1][_ll - 1];
}

int main(void) {
	int n;
	cin >> n;
	cout << g(n - 1, 1);
}