#include<iostream>
#include<queue>

using namespace std;

typedef long long int lli;

#define IT pair<lli, lli>
#define pk first
#define pt second

struct N {
	lli i, k, t;
};

struct ck {
	bool operator()(IT& _a, IT& _b) {
		if (_a.pt == _b.pt) return _a.pk > _b.pk;
		return _a.pt > _b.pt;
	}
};

struct cn {
	bool operator()(N& _a, N& _b) {
		if (_a.t == _b.t) return _a.k < _b.k;
		return _a.t > _b.t;
	}
};

lli n, k, bi, bt, i, r;
IT kb;
priority_queue<IT, vector<IT>, ck> ks;
priority_queue<N, vector<N>, cn> ns;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	for (lli _k(0); _k < k; _k++)
		ks.push({ _k, 0 });
	for (lli _n(0); _n < n; _n++) {
		cin >> bi >> bt;
		kb = ks.top(); ks.pop();
		ks.push({ kb.pk, kb.pt + bt });
		ns.push({ bi, kb.pk, kb.pt + bt });
	}
	while (!ns.empty()) {
		r += ns.top().i * ++i;
		ns.pop();
	}
	cout << r;
}