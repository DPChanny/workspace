#include<iostream>

using namespace std;

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	int t(min(n / 2, m));
	n -= 2 * t;
	m -= t;
	k -= n + m;
	if (k > 0) {
		t -= k / 3;
		k %= 3;
		t -= k != 0;
	}
	cout << t;
}