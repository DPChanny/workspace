#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

double xa, xb, xc, ya, yb, yc, ds[3];

int main(void) {
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	if((yb - ya) * (xc - xb) == (yc - yb) * (xb - xa)) {
		cout << -1;
		return 0;
	}

	ds[0] = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	ds[1] = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
	ds[2] = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));

	sort(ds, ds + 3);

	cout << fixed;
	cout.precision(16);
	cout << (ds[2] - ds[0]) * 2;
}
