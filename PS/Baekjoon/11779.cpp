#include<iostream>
#include<queue>
#include<stack>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> P;
#define pf first
#define ps second

lli n, m, bf, bt, bw;
P cn;
vector<lli> nws(1'000, INT64_MAX), nhs(1'000, -1);
vector<P> bs[1'000];
priority_queue<P> ns;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (lli _m(0); _m < m; _m++) {
		cin >> bf >> bt >> bw;
		bs[bf - 1].push_back({ bt - 1 , bw });
	}
	cin >> bf >> bt;
	ns.push({ bf - 1, nws[bf - 1] = 0 });
	while (!ns.empty()) {
		cn = ns.top(); ns.pop();
		if (nws[cn.pf] < cn.ps) continue;
		for (lli _b(0); _b < bs[cn.pf].size(); _b++)
			if (nws[cn.pf] + bs[cn.pf][_b].ps < nws[bs[cn.pf][_b].pf]) {
				ns.push({ bs[cn.pf][_b].pf, nws[bs[cn.pf][_b].pf] = nws[cn.pf] + bs[cn.pf][_b].ps });
				nhs[bs[cn.pf][_b].pf] = cn.pf;
			}
	}
	stack<lli> rhs;
	rhs.push(bt - 1);
	while (nhs[rhs.top()] != -1)
		rhs.push(nhs[rhs.top()]);
	cout << nws[bt - 1] << '\n' << rhs.size() << '\n';
	while (!rhs.empty()) {
		cout << rhs.top() + 1 << ' '; rhs.pop();
	}
}