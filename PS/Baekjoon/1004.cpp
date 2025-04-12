#include<iostream>

using namespace std;

int xa, xb, ya, yb, n, t, cx, cy, cr, ac, bc;

int main(void) {
	cin >> t;
	for(int _t(0); _t < t; _t++) {
		ac = bc = 0;
		cin >> xa >> ya >> xb >> yb >> n;
		for(int _n(0); _n < n; _n++) {
			cin >> cx >> cy >> cr;
			if((cx - xa) * (cx - xa) + (cy - ya) * (cy - ya) < cr * cr) {
				if((cx - xb) * (cx - xb) + (cy - yb) * (cy - yb) > cr * cr) ac++;
			}
			else if((cx - xb) * (cx - xb) + (cy - yb) * (cy - yb) < cr * cr) bc++;
		}
		cout << ac + bc << '\n';
	}
}