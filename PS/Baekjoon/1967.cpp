#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<uint16_t, uint16_t> edge;
typedef pair<uint16_t, uint32_t> point;
#define t first
#define v first
#define l second

uint16_t n, bf, bt, bl;
vector<edge> ns[10'000];
bool vs[10'000];
point mlp;

void gmlp(uint16_t _f, uint32_t _l) {
	vs[_f] = true;
	if(mlp.l < _l) mlp = make_pair(_f, _l);
	for(uint32_t _t(0); _t < ns[_f].size(); _t++)
		if(!vs[ns[_f][_t].t])
			gmlp(ns[_f][_t].t, _l + ns[_f][_t].l);
}

int32_t main(void) {
	cin >> n;
	for(int _n(0); _n < n - 1u; _n++) {
		cin >> bf >> bt >> bl;
		ns[bf - 1].push_back(make_pair(bt - 1u, bl));
		ns[bt - 1].push_back(make_pair(bf - 1u, bl));
	}
	gmlp(0, 0);
	memset(vs, false, sizeof(bool) * n);
	gmlp(mlp.v, 0);
	cout << mlp.l;
}