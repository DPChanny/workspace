#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	string ns;
	cin >> ns;
	int ln(0);
	int ck(k);
	for (int _n(0); _n < n; _n++) {
		while (ln && ck && ns[ln - 1] < ns[_n]) {
			ln--;
			ck--;
		}
		ns[ln++] = ns[_n];
	}
	for (int _n(0); _n < n - k; _n++)
		cout << ns[_n];
}
