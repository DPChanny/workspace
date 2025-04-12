#include<iostream>

using namespace std;

int main(void) {
	int n, l, t;
	bool ns[1000]{};
	cin >> n >> l;
	for (int _n(0); _n < n; _n++) {
		cin >> t;
		ns[t - 1] = true;
	}
	int c(0);
	for (int _n(0); _n < 1000; _n++) {
		if (ns[_n]) {
			c++;
			_n += l - 1;
		}
	}
	cout << c;
}