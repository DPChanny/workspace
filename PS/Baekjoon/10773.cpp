#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	int k;
	cin >> k;

	stack<int> memory;
	int buf;
	for (size_t _k(0); _k < k; _k++)
	{
		cin >> buf;
		if (!buf) {
			memory.pop();
			continue;
		}
		memory.push(buf);
	}

	int sum(0);
	while (!memory.empty()) {
		sum += memory.top();
		memory.pop();
	}
	cout << sum;
}