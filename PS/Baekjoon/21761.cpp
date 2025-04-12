#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct N {
	uint16_t t;
	uint32_t u;
	double r;
};

constexpr int A = 0;
constexpr int B = 1;
constexpr int C = 2;
constexpr int D = 3;

bool operator<(const N& _a, const N& _b) {
	return _a.r < _b.r;
}

char bt;
uint32_t n, k, nsc[4], ns[4][200000];
uint64_t nss[4];
priority_queue<N> rns;

int main() {
	cin >> n >> k  >> nss[A] >> nss[B] >> nss[C] >> nss[D];
	for(uint32_t _n(0); _n < n; _n++) {
		cin >> bt;
		cin >> ns[bt - 'A'][nsc[bt - 'A']++];
	}
	for(uint16_t _t(A); _t < D + 1; _t++) {
		sort(ns[_t], ns[_t] + nsc[_t], greater<double>());
		for(uint32_t _nt(0); _nt < nsc[_t]; _nt++) {
			rns.push({ _t, ns[_t][_nt], (double)ns[_t][_nt] / (double)nss[_t] });
			nss[_t] += ns[_t][_nt];
		}
	}
	for(uint32_t _k(0); _k < k; _k++) {
		cout << (char)(rns.top().t + 'A') << ' ' << rns.top().u << '\n';
		rns.pop();
	}
}