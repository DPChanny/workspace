#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long int lli;

struct N {
	lli n, x, y, z;
};

bool cx(N& _a, N& _b) {
	return _a.x > _b.x;
}

bool cy(N& _a, N& _b) {
	return _a.y > _b.y;
}

bool cz(N& _a, N& _b) {
	return _a.z > _b.z;
}

struct E {
	lli f, t, w;
};

struct ce {
	bool operator()(E& _a, E& _b) {
		return _a.w > _b.w;
	}
};

lli n, nus[100'000 + 1], r;
N ns[100'000];
priority_queue<E, vector<E>, ce> es;

lli gu(lli _n) {
	if (!nus[_n]) return _n;
	return nus[_n] = gu(nus[_n]);
}

int main(void) {
	cin >> n;
	for (lli _n(0); _n < n; _n++) {
		ns[_n].n = _n + 1;
		cin >> ns[_n].x >> ns[_n].y >> ns[_n].z;
	}
	sort(ns, ns + n, cx);
	for (lli _n(0); _n < n - 1; _n++)
		es.push({ ns[_n].n, ns[_n + 1].n, abs(ns[_n + 1].x - ns[_n].x) });
	sort(ns, ns + n, cy);
	for (lli _n(0); _n < n - 1; _n++)
		es.push({ ns[_n].n, ns[_n + 1].n, abs(ns[_n + 1].y - ns[_n].y) });
	sort(ns, ns + n, cz);
	for (lli _n(0); _n < n - 1; _n++)
		es.push({ ns[_n].n, ns[_n + 1].n, abs(ns[_n + 1].z - ns[_n].z) });
	while (!es.empty()) {
		if (gu(es.top().f) != gu(es.top().t)) {
			nus[gu(es.top().f)] = gu(es.top().t);
			r += es.top().w;
		}
		es.pop();
	}
	cout << r;
}