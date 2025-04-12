#include<iostream>

using namespace std;

int n, k, ns[200'000], nus[100'001], l, c;

int main(void) {
	cin >> n >> k;
	for(int _n(0); _n < n; _n++) {
		cin >> ns[_n];
		nus[ns[_n]]++;
		while(nus[ns[_n]] > k && l < n) nus[ns[l++]]--;
		c = max(c, _n - l + 1);
	}
	cout << c;
}