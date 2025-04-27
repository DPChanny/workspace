#include<iostream>

using namespace std;

uint64_t n, m, k, t, d, ilc, olc, sb, eb, mb;

uint64_t gilc() {
	if(m == 2) return 1 * n;
	return (m + (m * (m - 3) / 2)) * n;
}

uint64_t golc() {
	return (n * m * m * (n - 1)) / 2;
}

int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for(uint64_t _t(0); _t < t; _t++) {
		cin >> n >> m >> k >> d;
		ilc = gilc(); olc = golc();
		sb = 0;
		eb = 200000000;
		while(sb + 1 != eb && sb != eb) {
			mb = (sb + eb) / 2;
			if(olc * mb + ilc * mb * k <= d) sb = mb;
			else eb = mb - 1;
		}
		while(ilc * sb * k + olc * sb <= d) sb++;
		sb--;
		if(!sb) cout << -1 << '\n';
		else cout << olc * sb + ilc * sb * k << '\n';
	}
}
