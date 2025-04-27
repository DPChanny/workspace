#include<iostream>
#include<algorithm>

using namespace std;

int n, m, l, ns[52], sd(1), ed, md, cm, cr;
bool f;

int main(void) {
	cin >> n >> m >> l;
	for(int _n(1); _n < n + 1; _n++)
		cin >> ns[_n];
	ns[n + 1] = l;
	sort(ns, ns + n + 2);
	for(int _n(0); _n < n + 2; _n++)
		md = max(md, ns[_n + 1] - ns[_n]);
	ed = md + 1;
	while(sd != ed) {
		f = false;
		cm = 0;
		md = (sd + ed) / 2;
		cr = ns[0];
		for(int _n(1); _n < n + 2; _n++) {
			if(ns[_n] - cr > md) {
				if(cm + 1 > m) {
					f = true;
					break;
				}
				cm++;
				cr += md;
				_n--;
			} else cr = ns[_n];
		}
		if(f) sd = md + 1;
		else ed = md;
	}
	cout << sd;
}