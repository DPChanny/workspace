#include<iostream>
#include<queue>

using namespace std;

int t, n;

struct N {
	int n, p60, p10, m10, p1, m1;
};

N bfs(int _n) {
	N cn;
	queue<N> qs;
	qs.push({ 0, 0, 0, 0, 0, 0 });
	while (!qs.empty()) {
		cn = qs.front(); qs.pop();
		if (cn.n == _n)
			return cn;
		if (cn.n + 1 > 1) qs.push({ cn.n - 1, cn.p60, cn.p10, cn.m10, cn.p1, cn.m1 + 1 });
		qs.push({ cn.n + 1, cn.p60,  cn.p10, cn.m10, cn.p1 + 1, cn.m1 });
		if (cn.n + 1 > 10) qs.push({ cn.n - 10, cn.p60, cn.p10, cn.m10 + 1, cn.p1, cn.m1 });
		qs.push({ cn.n + 10, cn.p60, cn.p10 + 1, cn.m10, cn.p1, cn.m1 });
		qs.push({ cn.n + 60, cn.p60 + 1, cn.p10, cn.m10, cn.p1, cn.m1 });
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	N rn;
	for (int _t(0); _t < t; _t++) {
		cin >> n;
		rn = bfs(n % 60);
		cout << rn.p60 + n / 60 << ' ' << rn.p10 << ' ' << rn.m10 << ' ' << rn.p1 << ' ' << rn.m1 << '\n';
	}
}