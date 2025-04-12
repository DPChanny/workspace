#include<iostream>

using namespace std;

int pns[1000000], pnc, m, n;
bool f;

int main(void){
	cin >> m >> n;

	for(int _n(2); _n < n + 1; _n++) {
		f = false;
		for(int _pn(0); _pn < pnc && _n >= pns[_pn] * pns[_pn]; _pn++)
			if(!(_n % pns[_pn])) {
				f = true;
				break;
			}
		if(!f) {
			pns[pnc++] = _n;
			if(_n + 1 > m) cout << _n << '\n';
		}
	}
}