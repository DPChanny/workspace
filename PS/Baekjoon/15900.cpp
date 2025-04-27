#include<iostream>
#include<vector>

using namespace std;

vector<uint32_t> ns[500'000];
uint32_t n, bf, bt;
uint64_t c;
bool vs[500'000]{ true, };

void gc(uint32_t _f, uint64_t _c) {
	bool f(false);
	vs[_f] = true;
	for(uint32_t _t(0); _t < ns[_f].size(); _t++)
		if(!vs[ns[_f][_t]]) {
			f = true;
			gc(ns[_f][_t], _c + 1);
		}
	if(!f) c += _c;
}

int main(void) {
	cin >> n;
	for(int _n(0); _n < n - 1; _n++) {
		cin >> bf >> bt;
		ns[bf - 1].push_back(bt - 1);
		ns[bt - 1].push_back(bf - 1);
	}
	gc(0, 0);
	cout << ((c % 2) ? "Yes" : "No");
}