#include<iostream>
#include<algorithm>

using namespace std;

int n, ns[10'001], m, c;

int main(void) {
	cin >> n >> m;
	for(int _n(1); _n < n + 1; _n++) {
		cin >> ns[_n];
		ns[_n] += ns[_n - 1];
	}
	for(int _n(1); _n < n + 1; _n++)
		if(binary_search(ns + _n, ns + n + 1, ns[_n - 1] + m))
			c++;
	cout << c;
}