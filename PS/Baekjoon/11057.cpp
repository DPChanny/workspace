#include<iostream>

using namespace std;

int dp[1000][10];

int cal(int _n, int _c) {
	if (!_n) {
		return 1;
	}

	if (!dp[_n - 1][_c]) {
		int sum(0);
		for (int __c(_c); __c < 10; __c++)
		{
			sum += cal(_n - 1, __c) % 10007;
		}

		dp[_n - 1][_c] = sum % 10007;
	}

	return dp[_n - 1][_c];
}

int main(void) {
	int n;
	cin >> n;

	cout << cal(n, 0);
}
