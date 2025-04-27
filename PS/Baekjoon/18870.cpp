#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, ns[1000000], uns[1000000], un(1);

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	memcpy(uns, ns, sizeof(ns));
	sort(uns, uns + n);
	for (int _n(1); _n < n; _n++)
		if (uns[_n - 1] != uns[_n])
			uns[un++] = uns[_n];
	for (int _n(0); _n < n; _n++)
		cout << lower_bound(uns, uns + un, ns[_n]) - uns << ' ';
}