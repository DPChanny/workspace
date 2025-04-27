#include<iostream>

using namespace std;

long long int ns[100000], dp[2][100001]{};

#define INT_MIN -1000

int main(void) {
	int n;
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];

	long long int m(INT_MIN);
	dp[0][0] = INT_MIN;
	dp[1][0] = INT_MIN;
	for (int _n(1); _n < n + 1; _n++) {
		dp[0][_n] = max(ns[_n - 1], dp[0][_n - 1] + ns[_n - 1]);
		dp[1][_n] = max(max(dp[0][_n - 1], dp[1][_n - 1] + ns[_n - 1]), ns[_n - 1]);
		m = max(max(m, dp[0][_n]), dp[1][_n]);
	}
	cout << m;
}