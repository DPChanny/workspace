#include<iostream>
#include<algorithm>

using namespace std;

int n, s, c(100'001), ns[100'001], * lbp;

int main(void) {
	cin >> n >> s;
	for(int _n(1); _n < n + 1; _n++) {
		cin >> ns[_n];
		ns[_n] += ns[_n - 1];
	}
	for(int _n(1); _n < n + 1; _n++) {
		lbp = lower_bound(ns + _n, ns + n + 1, ns[_n - 1] + s);
		if(lbp != ns + n + 1) c = min(c, (int)(lbp - ns) - _n + 1);
	}
	if(c != 100'001) cout << c;
	else cout << 0;
}