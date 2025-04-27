#include<iostream>
#include<algorithm>

using namespace std;

long long int n, k, ks[10'000];

long long int gc(long long int _l) {
	long long int c(0);
	for(long long int _k(k - 1); _k + 1 > 0 && ks[_k] + 1 > _l; _k--)
		c += ks[_k] / _l;
	return c;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;
	for(long long int _k(0); _k < k; _k++)
		cin >> ks[_k];
	sort(ks, ks + k);

	long long int sl(1), el(2147483648), ml, c;
	while(sl != el) {
		ml = (sl + el) / 2;
		c = gc(ml);
		if(c < n) el = ml;
		else sl = ml + 1;
	}
	cout << sl - 1;
}