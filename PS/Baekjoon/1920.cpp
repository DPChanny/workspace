#include<iostream>
#include<algorithm>

using namespace std;

int n, m, ns[100000], cm, s, e, mid;
bool f;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	cin >> m;
	for (int _m(0); _m < m; _m++) {
		cin >> cm;
		s = 0; e = n - 1;
		f = false;
		while (s <= e) {
			mid = (s + e) / 2;
			if (ns[mid] == cm) {
				f = true;
				break;
			}
			else if (ns[mid] > cm)
				e = mid - 1;
			else
				s = mid + 1;
		}
		cout << f << '\n';
	}
}