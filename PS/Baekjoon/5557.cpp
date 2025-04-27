#include<iostream>

using namespace std;

int n,
	ns[100];
unsigned long long int dp[100][21];

unsigned long long int cal(int _n, int _sum) {
	if (_sum < 0 || _sum > 20)
		return 0;
	if (_n == n - 1) {
		if (_sum == ns[_n]) 
			return 1;
		return 0;
	}

	if (!dp[_n][_sum])
		dp[_n][_sum] = cal(_n + 1, _sum - ns[_n]) + cal(_n + 1, _sum + ns[_n]);

	return dp[_n][_sum];
}

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	
	cout << cal(1, ns[0]) << '\n';
}