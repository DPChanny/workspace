#include <iostream>

using namespace std;

int 
	ns[1000], 
	dp[1000]{};

int main(void)
{
	int n;
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for (int _n(0); _n < n; _n++) {
		for (int i(0); i < _n; i++)
			if (ns[i] > ns[_n])
				dp[_n] = max(dp[_n], dp[i] + 1);
		if (!dp[_n]) dp[_n] = 1;
	}
	int m(0);
	for (int _n(0); _n < n; _n++)
		m = max(m, dp[_n]);
	cout << m;
}