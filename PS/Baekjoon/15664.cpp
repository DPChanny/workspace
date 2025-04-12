#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, ns[8];
vector<vector<int>> rs;
vector<int> sns;

void gc(int _n) {
	if(_n == n) {
		if(sns.size() == m) rs.push_back(sns);
		return;
	}
	if(sns.size() != m) {
		sns.push_back(ns[_n]);
		gc(_n + 1);
		sns.pop_back();
	}
	gc(_n + 1);
}

int main(void) {
	cin >> n >> m;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	gc(0);
	sort(rs.begin(), rs.end());
	rs.erase(unique(rs.begin(), rs.end()), rs.end());
	for(int _r(0); _r < rs.size(); _r++) {
		for(int _sn(0); _sn < rs[_r].size(); _sn++)
			cout << rs[_r][_sn] << ' ';
		cout << '\n';
	}	
}