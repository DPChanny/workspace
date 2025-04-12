#include<iostream>

using namespace std;

typedef long long int lli;

lli n, cs[5]{ 1, 0, 0, 0, 0 };
char bn;

lli gi(char _n) {
	switch (_n) {
	case 'D':
		return 1;
	case 'K':
		return 2;
	case 'S':
		return 3;
	case 'H':
		return 4;
	}
	return 0;
}

int main(void) {
	cin >> n;
	for (lli _n(0); _n < n; _n++) {
		cin >> bn;
		if (string("DKSH").find(bn) != string::npos)
			cs[gi(bn)] += cs[gi(bn) - 1];
	}
	cout << cs[4];
}