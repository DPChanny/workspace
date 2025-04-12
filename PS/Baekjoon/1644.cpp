#include<iostream>
#include<vector>

using namespace std;

int n, l, r, s, c;
bool ipns[4'000'000 + 1];
vector<int> pns;

int main(void) {
	for(int _pn(2); _pn  * _pn < 4'000'000 + 1; _pn++)
		if(!ipns[_pn])
			for(int _pnm(_pn); _pnm * _pn < 4'000'000 + 1; _pnm++)
				ipns[_pnm * _pn] = true;
	for(int _pn(2); _pn < 4'000'000 + 1; _pn++)
		if(!ipns[_pn]) pns.push_back(_pn);
	cin >> n;
	s = pns[0];
	while(true) {
		if(s == n) {
			c++;
			if(r + 1 < pns.size())
				s += pns[++r];
			else break;
		}
		else if(s < n) {
			if(r + 1 < pns.size())
				s += pns[++r];
			else break;
		}
		else {
			s -= pns[l++];
		}
	}
	cout << c;
}