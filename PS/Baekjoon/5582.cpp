#include<iostream>

using namespace std;
int dp[4001][4001] = { {0, }, };
int main(void) {
	string a, b;
	cin >> a >> b;
	
	int max(0);

	for (int _b = 0; _b < b.length(); _b++)
	{
		for (int _a = 0; _a < a.length(); _a++)
		{
			if (a[_a] == b[_b]) {
				dp[_b + 1][_a + 1] = dp[_b][_a] + 1;
				if (dp[_b + 1][_a + 1] > max)
					max = dp[_b + 1][_a + 1];
			}
		}
	}

	cout << max << endl;
}