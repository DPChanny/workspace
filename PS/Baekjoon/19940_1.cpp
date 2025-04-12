#include<iostream>
#include<queue>

using namespace std;

int t, n;

struct N {
	int n, p60, p10, m10, p1, m1;
};

bool nvs[60 + 1];
N ns[60 + 1];

void bfs() {
	N cn;
	queue<N> qs;
	qs.push({ 0, 0, 0, 0, 0, 0 });
	while (!qs.empty()) {
		cn = qs.front(); qs.pop();
		if (cn.n < 60 + 1 && cn.n + 1 > 0 && !nvs[cn.n]) {
			nvs[cn.n] = true;
			ns[cn.n] = cn;
			if (cn.n + 1 > 1) qs.push({ cn.n - 1, cn.p60, cn.p10, cn.m10, cn.p1, cn.m1 + 1 });
			qs.push({ cn.n + 1, cn.p60,  cn.p10, cn.m10, cn.p1 + 1, cn.m1 });
			if (cn.n + 1 > 10) qs.push({ cn.n - 10, cn.p60, cn.p10, cn.m10 + 1, cn.p1, cn.m1 });
			qs.push({ cn.n + 10, cn.p60, cn.p10 + 1, cn.m10, cn.p1, cn.m1 });
			qs.push({ cn.n + 60, cn.p60 + 1, cn.p10, cn.m10, cn.p1, cn.m1 });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	bfs();
	cin >> t;
	for (int _t(0); _t < t; _t++) {
		cin >> n;
		cout << n / 60 + ns[n % 60].p60 << ' ' << ns[n % 60].p10 << ' ' << ns[n % 60].m10 << ' ' << ns[n % 60].p1 << ' ' << ns[n % 60].m1 << '\n';
	}
}