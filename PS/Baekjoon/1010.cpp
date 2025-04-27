#include<iostream>
#include<cstring>

using namespace std;

int n, m, t, dp[30][30], s;

int main(void) {
	cin >> t;
	for(int _t(0); _t < t; _t++) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		for(int _m(0); _m < m; _m++) dp[0][_m] = 1;
		for(int _n(1); _n < n; _n++) {
			s = 0;
			for(int _m(_n); _m < m; _m++) {
				s += dp[_n - 1][_m - 1];
				dp[_n][_m] = s;
			}
		}
		s = 0;
		for(int _m(n - 1); _m < m; _m++) s += dp[n - 1][_m];
		cout << s << '\n';
	}
}