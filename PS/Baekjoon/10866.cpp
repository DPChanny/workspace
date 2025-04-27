#include<iostream>
#include<deque>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> d;
	int n, x;
	cin >> n;
	string c;
	for (int _n = 0; _n < n; _n++)
	{
		cin >> c;

		if (c == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (c == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (c == "size")
			cout << d.size() << '\n';
		else if (c == "empty")
			cout << d.empty() << '\n';
		else {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else if (c == "front")
				cout << d.front() << '\n';
			else if (c == "back")
				cout << d.back() << '\n';
			else if (c == "pop_front") {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
	}
}