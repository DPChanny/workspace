#include<iostream>
#include<vector>

using namespace std;

typedef long long int lli;
typedef pair<lli, char> E;
#define pf first
#define ps second

lli n, m, k, bea, beb, r;
char ns[1'000], bec;
vector<E> es[500];
vector<vector<lli>> dp(1'000 + 1, vector<lli>(500, -1));

lli gdp(lli _n, lli _m) {
	if (!_n) return 0;
	if (dp[_n][_m] == -1) {
		dp[_n][_m] = 0;
		for (lli _e(0); _e < es[_m].size(); _e++) {
			dp[_n][_m] = max(
				dp[_n][_m],
				gdp(_n - 1, es[_m][_e].pf) + (es[_m][_e].ps == ns[n - _n]) * 10);
		}
	}
	return dp[_n][_m];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (lli _n(0); _n < n; _n++)
		cin >> ns[_n];
	cin >> m >> k;
	for (lli _k(0); _k < k; _k++) {
		cin >> bea >> beb >> bec;
		es[bea - 1].push_back({ beb - 1, bec });
		es[beb - 1].push_back({ bea - 1, bec });
	}
	cout << gdp(n, 0);
}