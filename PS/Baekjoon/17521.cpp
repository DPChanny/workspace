#include<iostream>

using namespace std;

int  n, ns[15];
uint64_t w;

int main(void) {
	cin >> n >> w;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for(int _n(0); _n < n - 1; _n++)
		if(ns[_n + 1] - ns[_n] > 0)
			w = ns[_n + 1] * (w / ns[_n]) + w % ns[_n];
	cout << w;
}