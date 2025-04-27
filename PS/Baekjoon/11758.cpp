#include<iostream>

using namespace std;

int xa, ya, xb, yb, xc, yc, xu, yu, xv, yv, uxv;

int main(void) {
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	xu = xb - xa;
	yu = yb - ya;
	xv = xc - xa;
	yv = yc - ya;
	uxv = xu * yv - yu * xv;
	if(uxv > 0) cout << 1;
	else if(uxv < 0) cout << -1;
	else cout << 0;
}