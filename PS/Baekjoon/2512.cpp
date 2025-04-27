#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

uint16_t n;
uint32_t ns[10'000], m, l, r, c, cm;

int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(uint16_t _n(0u); _n < n; _n++) cin >> ns[_n];
	sort(ns, ns + n);
	cin >> m;
	r = ns[n - 1u] + 1u;
	while(l != r) {
		c = (l + r) / 2u;
		cm = 0u;
		for(uint16_t _n(0u); _n < n; _n++) {
			if(ns[_n] > c) cm += c;
			else cm += ns[_n];
		}
		if(cm > m) r = c;
		else l = c + 1u;
	}
	cout << l - 1u;
}
