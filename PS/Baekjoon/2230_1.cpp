#include<iostream>
#include<algorithm>

using namespace std;

int n, ns[100'000], m, c(2'000'000'000), l, r;

int main(void) {
	cin >> n >> m;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	while(r != n) {
		if(ns[r] - ns[l] < m) r++;
		else {
			c = min(c, ns[r] - ns[l]);
			l++;
		}
	}
	cout << c;
}