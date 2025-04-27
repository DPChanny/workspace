#include<iostream>
#include<queue>

using namespace std;

int n, s, e, u, d, t, _s;
bool vs[1000001];

int main(void) {
	cin >> n >> s >> e >> u >> d;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		_s = q.size();
		for (int __s(0); __s < _s; __s++) {
			if (q.front() == e) {
				cout << t;
				exit(EXIT_SUCCESS);
			}
			if (q.front() + u < n + 1 && !vs[q.front() + u]) {
				vs[q.front() + u] = true;
				q.push(q.front() + u);
			}
			if (q.front() - d > 0 && !vs[q.front() - d]) {
				vs[q.front() - d] = true;
				q.push(q.front() - d);
			}
			q.pop();
		}
		t++;
	}
	cout << "use the stairs";
}