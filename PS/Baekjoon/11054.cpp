#include<iostream>

using namespace std;

int main(void) {
	int n,
		* a;
	cin >> n;
	a = new int[n];
	for (int _n(0); _n < n; _n++)
		cin >> a[_n];

	int * inc_dp(new int[n]),
		* dec_dp(new int[n]);

	for (int _n(0); _n < n; _n++)
	{
		int m(0);
		for (int _m(0); _m < _n; _m++)
			if (a[_m] < a[_n])
				m = inc_dp[_m] > m ? inc_dp[_m] : m;
		inc_dp[_n] = m + 1;
	}
	for (int _n(n - 1); _n + 1 > 0; _n--)
	{
		int m(0);
		for (int _m(_n + 1); _m < n; _m++)
			if (a[_m] < a[_n])
				m = dec_dp[_m] > m ? dec_dp[_m] : m;
		dec_dp[_n] = m + 1;
	}

	int max(0);
	for (int _n(0); _n < n; _n++)
		max = inc_dp[_n] + dec_dp[_n] > max ? inc_dp[_n] + dec_dp[_n] : max;
	cout << max - 1 << endl;

	delete[] inc_dp;
	delete[] dec_dp;
	delete[] a;
}
