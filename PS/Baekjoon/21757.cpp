#include<iostream>
#include<numeric>

typedef long long int lli;

using namespace std;

lli n, ns[100'000LL], nss, cnss, rs[4LL]{ 1LL, 0LL, 0LL, 0LL };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (lli _n(0LL); _n < n; _n++)
		cin >> ns[_n];
	nss = accumulate(ns, ns + n, 0LL);
	if (!(nss % 4LL))
		for (lli _n(0LL); _n < n - 1LL; _n++) {
			cnss += ns[_n];
			for (lli _i(1LL); _i < 3LL + 1LL; _i++)
				if (cnss == nss / 4LL * _i)
					rs[_i] += rs[_i - 1LL];
		}
	cout << rs[3LL];
}