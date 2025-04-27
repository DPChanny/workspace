#include<iostream>
#include<queue>

using namespace std;

int n, x;
priority_queue<int, vector<int>, greater<int>> rq;
priority_queue<int, vector<int>, less<int>> lq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int _n(0); _n < n; _n++) {
		cin >> x;
		if (!rq.empty() && rq.top() < x) rq.push(x);
		else lq.push(x);
		if (abs((int)lq.size() - (int)rq.size()) > 1) {
			if (lq.size() < rq.size()) {
				lq.push(rq.top());
				rq.pop();
			} else {
				rq.push(lq.top());
				lq.pop();
			}
		}
		if (lq.size() < rq.size()) cout << rq.top() << '\n';
		else cout << lq.top() << '\n';
	}
}