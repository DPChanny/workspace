#include<iostream>
#include<queue>
#include<string>
#include<stack>

using namespace std;

int visit[100001];

int main(void) {
	for (int _n(0); _n < 100001; _n++)
		visit[_n] = -1;
	int n, k, t(0), s, c;
	cin >> n >> k;
	queue<int> q;
	visit[n] = -2;
	q.push(n);
	while (true) {
		s = q.size();
		for (int _q(0); _q < s; _q++) {
			c = q.front();
			if (c == k) {
				stack<int> rs;
				cout << t << '\n';
				rs.push(c);
				while (visit[rs.top()] != -2)
					rs.push(visit[rs.top()]);
				while (!rs.empty()) {
					cout << rs.top() << ' '; rs.pop();
				}
				return 0;
			}
			if (c < 100000)
				if (visit[c + 1] == -1) {
					visit[c + 1] = c;
					q.push(c + 1);
				}
			if (c > 0)
				if (visit[c - 1] == -1) {
					visit[c - 1] = c;
					q.push(c - 1);
				}
			if (c * 2 < 100001)
				if (visit[c * 2] == -1) {
					visit[c * 2] = c;
					q.push(c * 2);
				}
			q.pop();
		}
		t++;
	}
}