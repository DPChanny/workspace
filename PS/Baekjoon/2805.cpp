#include<iostream>
#include<algorithm>

using namespace std;

int n, m, ns[1'000'000], l, r, c;
long long int s;

int main(void) {
	cin >> n >> m;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	r = ns[n - 1] + 1;
	while(l != r) {
		c = (r + l) / 2;
		s = 0;
		for(int _n(0); _n < n; _n++)
			if(ns[_n] > c)
				s += ns[_n] - c;
		if(s + 1 > m) l = c + 1;
		else r = c;
	}
	cout << l - 1;
}