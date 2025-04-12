#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void) {
	queue<int> stack;

	size_t n;
	cin >> n;

	string cmd;
	for (size_t _n(0); _n < n; _n++) {
		cin >> cmd;

		if (!cmd.compare("push")) {
			cin >> cmd;
			stack.push(stoi(cmd));
			continue;
		}
		if (!cmd.compare("front")) {
			if (stack.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stack.front() << endl;
			}
			continue;
		}
		if (!cmd.compare("back")) {
			if (stack.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stack.back() << endl;
			}
			continue;
		}
		if (!cmd.compare("size")) {
			cout << stack.size() << endl;
			continue;
		}
		if (!cmd.compare("empty")) {
			cout << stack.empty() << endl;
			continue;
		}
		if (!cmd.compare("pop")) {
			if (stack.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stack.front() << endl;
				stack.pop();
			}
			continue;
		}
	}
}