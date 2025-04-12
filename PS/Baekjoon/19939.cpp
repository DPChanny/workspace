#include<iostream>

using namespace std;

int n, k, s;

int main(void) {
	cin >> n >> k;
	for (int _k(1); _k < k + 1; _k++)
		s += _k;
	if (n < s) cout << -1;
	else if ((n - s) % k) cout << k;
	else cout << k - 1;
}