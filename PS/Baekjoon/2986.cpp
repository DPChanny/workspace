#include<iostream>
#include<cmath>

using namespace std;

int n, c;
bool pns[40'000 + 1];

int main(void) {
	cin >> n;
	for(int _pn(2); _pn < sqrt(n) + 1; _pn++)
		if(!pns[_pn]) {
			if(!(n % _pn)) {
				c = n - n / _pn;
				break;
			}
			for(int _pnm(_pn); _pnm * _pn < 40'000 + 1; _pnm++)
				pns[_pnm * _pn] = true;
		}
	if(c) cout << c;
	else cout << n - 1;
}