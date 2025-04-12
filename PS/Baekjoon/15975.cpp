#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

uint32_t n, bx, bc;
vector<uint32_t> ns[100'000];
uint64_t l;

int32_t main(void) {
	cin >> n;
	for(uint32_t _n(0u); _n < n; _n++) {
		cin >> bx >> bc;
		ns[bc - 1].push_back(bx);
	}
	for(uint32_t _n(0u); _n < n; _n++) {
		vector<uint32_t>& xs = ns[_n];
		if(xs.size() > 1) {
			sort(xs.begin(), xs.end());
			l += xs[1u] - xs[0u];
			l += xs[xs.size() - 1u] - xs[xs.size() - 2u];
			for(uint32_t _x(1u); _x < xs.size() - 1u; _x++) {
				if(xs[_x + 1u] - xs[_x] < xs[_x] - xs[_x - 1u])
					l += xs[_x + 1u] - xs[_x];
				else  l += xs[_x] - xs[_x - 1u];
			}
		}
	}
	cout << l;
}