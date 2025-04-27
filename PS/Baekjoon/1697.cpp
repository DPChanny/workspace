#include<iostream>
#include<queue>

using namespace std;

int visit[100001]{};

int main(void) {
	int n, k, t(0);
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	while (true) {
		int s = q.size();
		for (int _q(0); _q < s; _q++) {
			if (q.front() == k) {
				cout << t;
				return 0;
			}
			if (q.front() < 0 ||
				q.front() > 100000 ||
				visit[q.front()]) {
				q.pop();
				continue;
			}
			visit[q.front()] = 1;
			q.push(q.front() + 1);
			q.push(q.front() - 1);
			q.push(q.front() * 2);
			q.pop();
		}
		t++;
	}
}