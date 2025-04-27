#include<iostream>
#include<algorithm>

using namespace std;

int l, c, ls[16];
char cs[15];
bool vs[15];

bool cv(const char& _a) {
	return _a == 'a' || _a == 'e' || _a == 'i' || _a == 'o' || _a == 'u';
}

void pp(int _l, int _vc) {
	if(_l == l) {
		if(_vc && l - _vc + 1 > 2) {
			for(int _l(1); _l < l + 1; _l++)
				cout << cs[ls[_l]];
			cout << '\n';
		}
		return;
	}
	for(int _c(ls[_l] + 1); _c < c; _c++) {
		ls[_l + 1] = _c;
		pp(_l + 1, _vc + vs[_c]);
	}
}

int main(void) {
	cin >> l >> c;
	for(int _c(0); _c < c; _c++)
		cin >> cs[_c];
	sort(cs, cs + c);
	for(int _c(0); _c < c; _c++)
		vs[_c] = cv(cs[_c]);
	ls[0] = -1;
	pp(0, 0);
}