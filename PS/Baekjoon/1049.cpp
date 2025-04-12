#include<iostream>

using namespace std;

int main(void) {
	int n, m, m1(1000), m6(1000), tm1, tm6;
	cin >> n >> m;
	for (int _m(0); _m < m; _m++) {
		cin >> tm6 >> tm1;
		m6 = min(m6, tm6);
		m1 = min(m1, tm1);
	}
	int ln(n), p(0);
	p = min(m1 * 6, m6) * (ln / 6);
	ln %= 6;
	p += min(ln * m1, m6);
	cout << p;
}