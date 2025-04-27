#include<iostream>

using namespace std;

int n, m, us[200 + 1], a, b;

int gu(int _n) {
	if (!us[_n]) return _n;
	return us[_n] = gu(us[_n]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int _y(0); _y < n; _y++)
		for (int _x(0); _x < n; _x++) {
			cin >> b;
			if (gu(_y + 1) != gu(_x + 1))
				if (b) us[gu(_y + 1)] = gu(_x + 1);
		}
	cin >> b;
	int _m(0);
	do {
		a = b;
		cin >> b;
	} while (++_m < m - 1 && gu(a) == gu(b));
	if (gu(a) == gu(b)) cout << "YES";
	else cout << "NO";
}