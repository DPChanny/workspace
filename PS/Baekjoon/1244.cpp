#include<iostream>

using namespace std;

int n, m, bg, bc;
bool ns[100];

int main(void) {
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	cin >> m;
	for(int _m(0); _m < m; _m++) {
		cin >> bg >> bc;
		if(!(bg - 1))
			for(int _i(bc - 1); _i < n; _i += bc)
				ns[_i] = !ns[_i];
		else {
			ns[bc - 1] = !ns[bc - 1];
			for(int _i(1); bc - _i > 0 && bc + _i - 1 < n; _i++) {
				if(ns[bc + _i - 1] != ns[bc - _i - 1]) break;
				ns[bc - _i - 1] = !ns[bc - _i - 1];
				ns[bc + _i - 1] = !ns[bc + _i - 1];
			}
		}
	}
	for(int _n(1); _n < n + 1; _n++) {
		if(!(_n % 20)) cout << ns[_n - 1] << '\n';
		else cout << ns[_n - 1] << ' ';
	}
}