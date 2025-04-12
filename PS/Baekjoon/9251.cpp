#include<iostream>

using namespace std;

int dp[1004][1004] = { {0, }, };

int main(void) {
	string a, b;
	cin >> a >> b;

	for (int _a(1); _a < a.length() + 1; _a++)
		for (int _b(1); _b < b.length() + 1; _b++) {
			if (a[_a - 1] == b[_b - 1]) dp[_a][_b] = dp[_a - 1][_b - 1] + 1;
			else dp[_a][_b] = max(dp[_a][_b - 1], dp[_a - 1][_b]);
		}
	
	cout << dp[a.length()][b.length()] << endl;
}