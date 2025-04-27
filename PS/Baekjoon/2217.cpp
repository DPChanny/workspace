#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	unsigned int
		n,
		ns[100000];
	vector<unsigned int> ms;
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	reverse(ns, ns + n);
	for (int _n(0); _n < n; _n++)
		ms.push_back((_n + 1) * ns[_n]);
	unsigned int m(0);
	for (int _n(0); _n < n; _n++)
		m = max(m, ms[_n]);
	cout << m;
}