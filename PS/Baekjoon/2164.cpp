#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	queue<int> q;

	int n;
	cin >> n;
	for (int _n(0); _n < n; _n++)
		q.push(_n + 1);

	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}