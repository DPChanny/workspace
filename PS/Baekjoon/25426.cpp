#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> P;
#define pf first
#define ps second

lli n, s;
P fs[100'000];

int main(void) {
	cin >> n;
	for (lli _n(0); _n < n; _n++)
		cin >> fs[_n].pf >> fs[_n].ps;
	sort(fs, fs + n);
	for (lli _n(0); _n < n; _n++)
		s += fs[_n].pf * (_n + 1) + fs[_n].ps;
	cout << s;
}