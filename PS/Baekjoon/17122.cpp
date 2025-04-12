#include<iostream>

using namespace std;

int n, b;
string a;

bool gc(int _n) {
	return (((_n / 8) + (_n % 8 ? 1 : 0)) % 2 == _n % 2);
}

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++) {
		cin >> a >> b;
		if (gc((int)(a[1] - '1') * 8 + (int)(a[0] - 'A') + 1) == gc(b)) cout << "YES\n";
		else cout << "NO\n";
	}
}