#include<iostream>
#include<algorithm>

using namespace std;

int n, m, ns[500000], ms[500000];

bool bs(int _m) {
	int s(0), e(n - 1), m;
	while(s <= e) {
		m = (s + e) / 2;
		if(ns[m] == ms[_m]) return true;
		else if(ns[m] > ms[_m]) e = m - 1;
		else s = m + 1;
	}
	return false;
}

int main(void) {
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	cin >> m;
	for(int _m(0); _m < m; _m++) 
		cin >> ms[_m];
	sort(ns, ns + n);
	for(int _m(0); _m < m; _m++)
		cout << bs(_m) << ' ';
}