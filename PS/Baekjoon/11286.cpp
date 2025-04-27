#include<queue>
#include<iostream>

using namespace std;

struct compare {
	bool operator()(const int& _a, const int& _b) {
		if (abs(_a) == abs(_b)) return _a > _b;
		return abs(_a) > abs(_b);
	}
};

priority_queue<int, vector<int>, compare> pq;
int n, x;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int _n(0); _n < n; _n++) {
		cin >> x;
		if (x) pq.push(x);
		else if (pq.empty()) cout << 0 << '\n';
		else {
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
}