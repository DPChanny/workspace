#include<iostream>

using namespace std;

int main(void) {
	string a;
	cin >> a;

	int m(1);
	int r(0);
	int t(0);
	for (int _a(0); _a < a.length(); _a++)
	{
		if (a[_a] == '+') {
			r += m * t;
			t = 0;
		}
		else if (a[_a] == '-') {
			r += m * t;
			t = 0;
			m = -1;
		}
		else {
			t *= 10;
			t += a[_a] - '0';
		}
	}
	r += m * t;
	cout << r;
}
