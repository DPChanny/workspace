#include<iostream>

using namespace std;

int m, bx, by, b(1);

int main(void) {
	cin >> m;
	for(int _m(0); _m < m; _m++) {
		cin >> bx >> by;
		if(bx == b) b = by;
		else if(by == b) b = bx;
	}
	cout << b;
}