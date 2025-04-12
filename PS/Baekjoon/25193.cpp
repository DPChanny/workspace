#include<iostream>

using namespace std;

typedef long long int lli;

lli n, c;
char b;

int main(void) {
	cin >> n;
	for (lli _n(0); _n < n; _n++) {
		cin >> b;
		if (b == 'C') c++;
	}
	cout << c / (n - c + 1) + (bool)(c % (n - c + 1));
}