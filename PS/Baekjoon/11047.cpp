#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int n, k, a[10];
	cin >> n >> k;
	for (int _n(0); _n < n; _n++)
		cin >> a[_n];
	sort(a, a + n);
	reverse(a, a + n);
	int c(0);
	for (int _n(0); k; _n++) {
		c += k / a[_n];
		k %= a[_n];
	}
	cout << c;
}