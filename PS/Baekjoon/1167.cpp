#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, int> point;
#define t first
#define v first
#define l second

int n, bf, bt, bl;
vector<edge> ns[100'000];
bool vs[100'000];
point mlp;

void gmlp(int _f, int _l) {
	vs[_f] = true;
	if (mlp.l < _l) mlp = make_pair(_f, _l);
	for (int _t(0); _t < ns[_f].size(); _t++)
		if (!vs[ns[_f][_t].t])
			gmlp(ns[_f][_t].t, _l + ns[_f][_t].l);
}

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++) {
		cin >> bf >> bt;
		while (bt != -1) {
			cin >> bl;
			ns[bf - 1].emplace_back(bt - 1, bl);
			cin >> bt;
		}
	}
	gmlp(0, 0);
	memset(vs, false, sizeof(bool) * n);
	gmlp(mlp.v, 0);
	cout << mlp.l;
}