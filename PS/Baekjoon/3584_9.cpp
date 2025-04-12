#include<iostream>
#include<cstring>

using namespace std;

int t, n, b1, b2, nps[10'000 + 1];
bool nvs[10'000 + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	for (int _t(0); _t < t; _t++) {
		cin >> n;
		for (int _n(0); _n < n - 1; _n++) {
			cin >> b1 >> b2;
			nps[b2] = b1;
		}
		cin >> b1 >> b2;
		nvs[b1] = true;
		while (nps[b1]) nvs[b1 = nps[b1]] = true;
		while (!nvs[b2]) b2 = nps[b2];
		cout << b2 << '\n';
		memset(nvs, false, sizeof(bool) * n + 1);
		memset(nps, 0, sizeof(int) * n + 1);
	}
}