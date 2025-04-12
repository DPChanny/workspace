#include<iostream>
#include<queue>

using namespace std;

int n, m, bf, bt, c(0);
bool
	ms[1000][1000]{ false, },
	vs[1000]{ false, };

void dfs(int _f) {
	for (int _t(0); _t < n; _t++)
		if (ms[_f][_t] && !vs[_t]) {
			vs[_t] = true;
			dfs(_t);
		}
}

int main(void) {
	cin >> n >> m;
	if (!m) {
		cout << n;
		exit(EXIT_SUCCESS);
	}
	for (int _m(0); _m < m; _m++) {
		cin >> bf >> bt;
		ms[bf - 1][bt - 1] = ms[bt - 1][bf - 1] = true;
	}
	for (int _f(0); _f < n; _f++)
		if (!vs[_f]) {
			vs[_f] = true;
			dfs(_f);
			c++;
		}
	cout << c;
}
