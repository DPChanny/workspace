#include<iostream>
#include<algorithm>

using namespace std;

int n, c, ns[200'000], l, m, r;
int* lub;
bool f;

int main(void) {
	cin >> n >> c;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	r = 1e9 + 1;
	while(l != r) {
		f = false;
		m = (r + l) / 2;
		lub = ns;
		for(int _c(1); _c < c; _c++) {
			lub = upper_bound(lub, ns + n, (*lub) + m - 1);
			if(lub == ns + n) {
				f = true;
				break;
			}
		}
		if(f) r = m;
		else l = m + 1;
	}
	cout << l - 1;
}