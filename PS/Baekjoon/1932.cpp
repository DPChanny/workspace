#include<iostream>

using namespace std;

long long int 
	dp[501][501]{},
	ns[501][501];

int main(void) {
	int n;
	cin >> n;
	for (int _y(1); _y < n + 1; _y++)
		for (int _x(1); _x < _y + 1; _x++)
			cin >> ns[_y][_x];
	for (int _y(1); _y < n + 1; _y++)
		for (int _x(1); _x < _y + 1; _x++)
			dp[_y][_x] = max(dp[_y - 1][_x], dp[_y - 1][_x - 1]) + ns[_y][_x];
	int m(0);
	for (int _x(1); _x < n + 1; _x++)
		m = m < dp[n][_x] ? dp[n][_x] : m;
	cout << m;
}