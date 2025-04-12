#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct line {
	int n, s, e;
};
bool operator<(const line& _a, const line& _b) {
	if(_a.s == _b.s) return _a.e > _b.e;
	return _a.s < _b.s;
}
vector<line> ls;

int n, m, bs, be;
bool rls[500'000];

int main(void) {
	cin >> n >> m;
	for(int _m(0); _m < m; _m++) {
		cin >> bs >> be;
		if(bs > be) ls.push_back({ _m, bs, be + n });
		else {
			ls.push_back({ _m, bs, be });
			ls.push_back({ _m, bs + n, be + n });
		}
	}
	sort(ls.begin(), ls.end());
	int me(ls[0].e);
	for(int _l(1); _l < ls.size(); _l++)
		if(ls[_l].e < me + 1) rls[ls[_l].n] = true;
		else me = ls[_l].e;
	for(int _m = 0; _m < m; _m++)
		if(!rls[_m]) cout << _m + 1 << ' ';
}