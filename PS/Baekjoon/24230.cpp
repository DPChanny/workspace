#include<iostream>
#include<vector>

using namespace std;

uint32_t n, cs[200'000], bf, bt;
uint64_t c;
vector<uint32_t> ns[200'000];
bool vs[200'000];

void gc(uint32_t _f, uint32_t _c) {
	vs[_f] = true;
	if(cs[_f] != _c) c++;
	for(uint32_t _t(0); _t < ns[_f].size(); _t++)
		if(!vs[ns[_f][_t]]) gc(ns[_f][_t], cs[_f]);
}

int32_t main(void) {
	cin >> n;
	for(uint32_t _n(0); _n < n; _n++)
		cin >> cs[_n];
	for(uint32_t _n(0); _n < n - 1; _n++) {
		cin >> bf >> bt;
		ns[bf - 1].push_back(bt - 1);
		ns[bt - 1].push_back(bf - 1);
	}
	gc(0, 0);
	cout << c;
}