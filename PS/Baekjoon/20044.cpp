#include<iostream>
#include<algorithm>

using namespace std;

int n, ns[100000];

int main(void) {
	cin >> n;
	for(int _n(0); _n < n * 2; _n++)
		cin >> ns[_n];
	sort(ns, ns + n * 2);
	for(int _n(0); _n < n; _n++)
		ns[_n] = ns[_n] + ns[n * 2 - _n - 1];
	cout << *min_element(ns, ns + n);
}