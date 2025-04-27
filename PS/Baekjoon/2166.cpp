#include <iostream>
#include <math.h>
using namespace std;
double xys[10000][2];

int n;
double w;

double gcp(int a, int b, int c) {
	return (xys[b][0] - xys[a][0]) * (xys[c][1] - xys[a][1]) - (xys[b][1] - xys[a][1]) * (xys[c][0] - xys[a][0]);
}

int main() {
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> xys[_n][0] >> xys[_n][1];
	for(int _n(1); _n < n - 1; _n++)
		w += gcp(0, _n, _n + 1) / 2;
	cout.precision(1);
	cout << fixed;
	cout << abs(w);
}
