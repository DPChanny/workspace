#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int n, ns[1001];
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	ns[n] = 0;
	if (ns[0] != 1) {
		cout << 1;
		return 0;
	}
	int s(0);
	for (int _n(0); _n < n; _n++) {
		s += ns[_n];
		if (ns[_n + 1] > s + 1)
			break;
	}
	cout << s + 1;
}