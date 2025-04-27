#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>

using namespace std;

int t, s, a, b, cq, nq, h, l;
bool pns[10'000], pnvs[10'000];

int main(void) {
	for(int _pn(2); _pn * _pn < 10'000; _pn++)
		if(!pns[_pn])
			for(int _pnm(_pn); _pnm * _pn < 10'000; _pnm++)
				pns[_pnm * _pn] = true;
	cin >> t;
	for(int _t(0); _t < t; _t++) {
		bool f(false); int r(0);
		cin >> a >> b;
		queue<int> q;
		pnvs[a] = true;
		q.push(a);
		while(!q.empty()) {
			s = q.size();
			for(int _s(0); _s < s; _s++) {
				cq = q.front(); q.pop();
				if(cq == b) {
					f = true; break;
				}
				for(int _d(1); _d < 4 + 1; _d++) {
					h = cq / (int)pow(10, _d);
					l = cq % (int)pow(10, _d - 1);
					for(int _i(0); _i < 9 + 1; _i++) {
						nq = h * (int)pow(10, _d) + _i * (int)pow(10, _d - 1) + l;
						if(nq + 1 > 1000 && !pns[nq] && !pnvs[nq]) {
							pnvs[nq] = true;
							q.push(nq);
						}
					}
				}
			}
			if(f) break;
			r++;
		}
		if(f) cout << r << '\n';
		else cout << "Impossible" << '\n';
		memset(pnvs, false, sizeof(pnvs));
	}
}