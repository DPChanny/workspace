#include<iostream>
#include<algorithm>
#include <numeric>
#include<vector>

using namespace std;

int main(void) {
	string n;
	vector<int> ns;

	cin >> n;
	for (int _n(0); _n < n.size(); _n++)
		ns.push_back(n[_n] - '0');

	if (find(ns.begin(), ns.end(), 0) == ns.end()) {
		cout << -1;
		return 0;
	}

	if (accumulate(ns.begin(), ns.end(), 0) % 3)
		cout << -1;
	else {
		sort(ns.begin(), ns.end());
		reverse(ns.begin(), ns.end());
		for (int _n(0); _n < ns.size(); _n++)
			cout << ns[_n];
	}
}
