#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	int tc,
		nc,
		ns[100]{ 0, },
		m;

	cin >> tc;

	for (int _t(0); _t < tc; _t++)
	{
		queue<int> q;

		cin >> nc >> m;
		for (int _n(0); _n < nc; _n++) {
			cin >> ns[_n];
			q.push(_n);
		}

		int c(0);
		while (true) {
			if (ns[q.front()] < *max_element(ns, ns + nc)) {
				q.push(q.front());
				q.pop();
			}
			else {
				c++;
				ns[q.front()] = -1;
				if (q.front() == m) {
					cout << c << '\n';
					break;
				}
				q.pop();
			}
		}
	}
}