#include<iostream>
#include<algorithm>

using namespace std;

long long int n, ns[5000], m(1e10), s, e, a, b, c;

int main(void) {
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	for(long long int _n(0); _n < n - 2; _n++) {
		s = _n + 1;
		e = n - 1;
		while(s < e) {
			if(m > abs(ns[_n] + ns[s] + ns[e])) {
				m = abs(ns[_n] + ns[s] + ns[e]);
				a = ns[_n]; b = ns[s]; c = ns[e];
			}
			if(!(ns[_n] + ns[s] + ns[e])) {
				cout << ns[_n] << ' ' << ns[s] << ' ' << ns[e];
				exit(EXIT_SUCCESS);
			}
			if(ns[_n] + ns[s] + ns[e] < 0) s++;
			else e--;
		}
	}
	cout << a << ' ' << b << ' ' << c;
}