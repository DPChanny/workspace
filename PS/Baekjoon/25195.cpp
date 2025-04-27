#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long int lli;

lli n, m, bf, bt, f;
vector<lli> es[100'000];
bool fs[100'000];

int main(void) {
	cin >> n >> m;
	for (lli _m(0); _m < m; _m++) {
		cin >> bf >> bt;
		es[bf - 1].push_back(bt - 1);
	}
	cin >> f;
	for (lli _f(0); _f < f; _f++) {
		cin >> bf;
		fs[bf - 1] = true;
	}
	queue<lli> ns;
	lli cn;
	ns.push(0);
	while (!ns.empty()) {
		cn = ns.front();
		ns.pop();
		if (fs[cn]) continue;
		if (es[cn].empty()) {
			cout << "yes";
			exit(EXIT_SUCCESS);
		}
		for (lli _t(0); _t < es[cn].size(); _t++)
			ns.push(es[cn][_t]);
	}
	cout << "Yes";
}