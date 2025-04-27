#include<iostream>

using namespace std;

int n, k, c, ns[30'000], t, r, nus[3'001];

int main(void) {
	cin >> n >> k >> k >> c;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for(int _k(0); _k < k; _k++)
		if(!nus[ns[(_k < n ? _k : _k - n)]]++) t++;
	for(int _i(0); _i + k < n + n; _i++) {
		r = max(r, t + !nus[c]);
		if(!--nus[ns[(_i < n ? _i : _i - n)]]) t--;
		if(!nus[ns[(_i + k < n ? _i + k : _i + k - n)]]++) t++;
	}
	cout << r;
}