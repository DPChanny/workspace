#include<iostream>

using namespace std;

int n;
bool dp[1000]{ true, false, true, true, };

int main(void) {
	cin >> n;
	for(int _n(4); _n < n; _n++)
		dp[_n] = !dp[_n - 1] || !dp[_n - 3] || !dp[_n - 4];
	cout << (dp[n - 1] ? "SK" : "CY");
}