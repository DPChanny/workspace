#include<iostream>

using namespace std;

typedef long long int lli;

lli n, ts[100], ss[100], f;

int main(void) {
	cin >> n;
	for (lli _n(0); _n < n; _n++)
		cin >> ts[_n] >> ss[_n];
	for (lli _n(0); _n < n; _n++)
		if (ss[_n] > ss[f]) f = _n;
	if (ss[f]) cout << ts[f] + f * 20;
	else cout << '0';
}