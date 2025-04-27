#include<iostream>
#include<stack>

using namespace std;

typedef unsigned long long int lli;
typedef pair<lli, lli> pll;
#define pf first
#define ps second

lli n, m, bn;
stack<pll> ns;

void gm(lli _n) {
	if (ns.empty()) return;
	lli s = ns.top().ps, l = ns.top().ps;
	bool r(false);
	while (!ns.empty() && ns.top().pf > _n) {
		r = true;
		m = max(m, ns.top().pf * (s - ns.top().ps + 1));
		l = ns.top().ps;
		ns.pop();
	}
	if (r) ns.emplace(_n, l);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	while (n) {
		for (lli _n(0); _n < n; _n++) {
			cin >> bn; gm(bn);
			ns.emplace(bn, _n);
		}
		gm(0);
		cout << m << '\n';
		m = 0;
		ns = stack<pll>();
		cin >> n;
	}
}