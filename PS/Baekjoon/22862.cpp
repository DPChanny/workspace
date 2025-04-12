#include<iostream>

using namespace std;

int n, k, ns[1'000'000], l, r, ck, c;

int main(void) {
	cin >> n >> k;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	while(r < n) {
		if(ck < k + 1) {
			if(ns[r++] % 2) ck++;
			c = max(c, r - l - ck);
		} else if(ns[l++] % 2) ck--;
	}
	cout << c;
}