#include<iostream>
#include<algorithm>

using namespace std;

struct line {
	int f, t, w;
};
bool operator<(const line& _a, const line& _b) {
	return _a.w < _b.w;
}

int n, fs[10'001], e, r;
line ls[1'00'000];

int f(int _n) {
	return fs[_n] == _n ? _n : fs[_n] = f(fs[_n]);
}

int main(void) {
	for(int _f(0); _f < 10'001; _f++)
		fs[_f] = _f;
	cin >> n >> e;
	for(int _e(0); _e < e; _e++)
		cin >> ls[_e].f >> ls[_e].t >> ls[_e].w;
	sort(ls, ls + e);
	for(int _e(0); _e < e; _e++) {
		if(f(ls[_e].f) != f(ls[_e].t)) {
			r += ls[_e].w;
			fs[f(ls[_e].t)] = f(ls[_e].f);
		}
	}
	cout << r;
}