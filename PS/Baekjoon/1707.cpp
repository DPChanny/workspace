#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int t, v, e, bf, bt;
vector<int> vs[20000];
int cs[20000];

void set(int _f, int _c) {
	for (int _t(0); _t < vs[_f].size(); _t++) {
		if (!cs[vs[_f][_t]]) {
			cs[vs[_f][_t]] = _c;
			set(vs[_f][_t], -_c);
		}
	}
}

bool check() {
	for (int _f = 0; _f < v; _f++)
		for (int _t = 0; _t < vs[_f].size(); _t++)
			if (cs[_f] == cs[vs[_f][_t]])
				return false;
	return true;
}

int main(void) {
	cin >> t;
	for (int _t = 0; _t < t; _t++) {
		for (int _f = 0; _f < v; _f++)
			vs[_f].clear();
		memset(cs, 0, sizeof(cs));
		cin >> v >> e;
		for (int _e = 0; _e < e; _e++) {
			cin >> bf >> bt;
			vs[bf - 1].push_back(bt - 1);
			vs[bt - 1].push_back(bf - 1);
		}
		for (int _f = 0; _f < v; _f++)
			if (!cs[_f])
				set(_f, 1);
		if (check())cout << "YES\n";
		else cout << "NO\n";
	}
}