#include<iostream>
#include<algorithm>

using namespace std;

int n, ns[100'000], l, r, c(2'000'000'001), a, b;

int main(void) {
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	r = n - 1;
	while(l != r) {
		if(c > abs(ns[l] + ns[r])) {
			c = abs(ns[l] + ns[r]);
			a = ns[l];
			b = ns[r];
		}
		if(!(ns[l] + ns[r])) break;
		else if(ns[l] + ns[r] > 0) r--;
		else l++;
	}
	cout << a << ' ' << b;
}