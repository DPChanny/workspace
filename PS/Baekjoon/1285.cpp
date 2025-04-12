#include<iostream>

using namespace std;

int n, x[32], c(1024);
bool ns[32][32];

int main(void) {
	cin >> n;
	for(int _y(0); _y < n; _y++) {
		getchar();
		for(int _x(0); _x < n; _x++)
			if(ns[_y][_x] = getchar() - 'H') x[_x]++;
	}
	for(int _b(0); _b < (1 << n); _b++) {
		int s(0);
		for(int _x(0); _x < n; _x++) {
			int tc(x[_x]);
			for(int _y(0); _y < n; _y++)
				if(_b & (1 << _y))
					if(ns[_y][_x]) tc--;
					else tc++;
			s += min(tc, n - tc);
		}
		c = min(c, s);
	}
	cout << c;
}