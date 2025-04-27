#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, t;
string ns[10'000];

bool c() {
	for(int _n(0); _n + 1 < n; _n++)
		if(ns[_n].size() < ns[_n + 1].size())
			if(!strncmp(ns[_n].c_str(), ns[_n + 1].c_str(), ns[_n].size())) return false;
	return true;
}

int main(void) {
	cin >> t;
	for(int _t(0); _t < t; _t++) {
		cin >> n;
		for(int _n(0); _n < n; _n++)
			cin >> ns[_n];
		sort(ns, ns + n);
		cout << (c() ? "YES\n" : "NO\n");
	}
}