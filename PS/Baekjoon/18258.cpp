#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	cout.tie(NULL);
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	queue<int> q;

	int n, x;
	cin >> n;

	string cmd;
	for (size_t _n(0); _n < n; _n++)
	{
		cin >> cmd;

		if (cmd == "push") {
			cin >> x;
			q.push(x);
		}
		else if (cmd == "size")
			cout << q.size() << '\n';
		else if (cmd == "empty")
			cout << q.empty() << '\n';
		else {
			if (q.empty())
				cout << -1 << '\n';
			else if (cmd == "front")
				cout << q.front() << '\n';
			else if (cmd == "back")
				cout << q.back() << '\n';
			else if (cmd == "pop") {
					cout << q.front() << '\n';
					q.pop();
			}
		}
	}
}