#include<iostream>
#include<deque>
#include<vector>
#include<cstdlib>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	deque<int> d;
	vector<int> ns(n);
	for (int _n(0); _n < n; _n++) {
		cin >> ns[_n];
		d.push_back(_n);
	}

	while (!d.empty()) {
		cout << d.front() + 1 << ' ';
		int i(ns[d.front()]);
		d.pop_front();
		if (!d.empty()) {
			if (i < 0)
				for (int _i(0); _i < abs(i); _i++) {
					d.push_front(d.back());
					d.pop_back();
				}
			else if (i > 0)
				for (int _i(0); _i < abs(i) - 1; _i++) {
					d.push_back(d.front());
					d.pop_front();
				}
		}
	}
}