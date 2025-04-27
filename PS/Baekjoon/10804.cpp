#include<iostream>

using namespace std;

int ns[20], bf, bt;

int main(void) {
	for(int _n(0); _n < 20; _n++)
		ns[_n] = _n + 1;
	for(int _t(0); _t < 10; _t++) {
		cin >> bf >> bt;
		for(int _f(0); _f < (bt - bf + 1) / 2; _f++)
			swap(ns[bf + _f - 1], ns[bt - _f - 1]);
	}
	for(int _n(0); _n < 20; _n++)
		cout << ns[_n] << ' ';
}