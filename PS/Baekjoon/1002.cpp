#include<iostream>
#include<cmath>

using namespace std;

int xa, ya, xb, yb, ra, rb, t;
double xyd, rrd;

int main(void) {
	cin >> t;
	for(int _t(0); _t < t; _t++) {
		cin >> xa >> ya >> ra >> xb >> yb >> rb;
		xyd = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
		rrd = sqrt((ra + rb) * (ra + rb));
		if(!xyd) cout << (ra == rb) * -1;
		else {
			if(rrd == xyd) cout << 1;
			else if(rrd < xyd) cout << 0;
			else {
				if(ra > xyd + rb) cout << 0;
				else if(rb > xyd + ra) cout << 0;
				else if(ra == xyd + rb) cout << 1;
				else if(rb == xyd + ra) cout << 1;
				else cout << 2;
			}
		}
		cout << '\n';
	}
}