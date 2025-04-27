#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

class N {
public:
	int m;
	int v;

	bool operator<(const N &_n) {
		return this->m < _n.m;
	}
};

N ns[300000];
int ks[300000];

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n].m >> ns[_n].v;
	for (int _k(0); _k < k; _k++)
		cin >> ks[_k];
	sort(ns, ns + n);
	sort(ks, ks + k);
	priority_queue<int> pns;
	long long int s(0);
	int pnsi(0);
	for (int _k(0); _k < k; _k++) {
		while (pnsi < n && ns[pnsi].m < ks[_k] + 1)
			pns.push(ns[pnsi++].v);
		if (!pns.empty()) {
			s += pns.top(); pns.pop();
		}
	}
	cout << s;
}