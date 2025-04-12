#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>

using namespace std;

int n, k, bx, by, s;
long long int ds[1002][1002];
bool v[1002]{ false, };
vector<pair<int, int>> ns;

bool check(long long int _md) {
	memset(v, false, sizeof(v));
	int _k(0);
	queue<int> q;
	q.push(0);
	while (!q.empty() && _k++ < k + 1) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			for (int _n(1); _n < ns.size(); _n++) {
				if (v[_n]) continue;
				if (ds[q.front()][_n] > _md) continue;
				if (_n == ns.size() - 1) return true;
				q.push(_n);
				v[_n] = true;
			}
			q.pop();
		}
	}
	return false;
}

int main(void) {
	cin >> n >> k;
	ns.push_back(make_pair(0, 0));
	for (int _n(0); _n < n; _n++) {
		cin >> bx >> by;
		ns.push_back(make_pair(bx, by));
	}
	ns.push_back(make_pair(10000, 10000));
	long long int d;
	for (int _f(0); _f < ns.size(); _f++) {
		for (int _t(_f); _t < ns.size(); _t++) {
			d = pow(ns[_f].first - ns[_t].first, 2) + pow(ns[_f].second - ns[_t].second, 2);
			ds[_f][_t] = d;
			ds[_t][_f] = d;
		}
	}
	int fl(1), fm(14143), m;
	long long int md;
	while (fl <= fm) {
		m = (fm + fl) / 2;
		md = pow(m, 2) * 100;
		if (check(md)) fm = m - 1;
		else fl = m + 1;
	}
	cout << fl;
}
