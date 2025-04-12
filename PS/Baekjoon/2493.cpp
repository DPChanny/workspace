#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> ns(n);
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	stack<int> s;
	for (int _n(0); _n < n; _n++)
	{
		bool f(false);
		while (!s.empty()) {
			if (ns[s.top()] > ns[_n]) {
				cout << s.top() + 1 << ' ';
				s.push(_n);
				f = true;
				break;
			}
			s.pop();
		}
		if (!f) {
			cout << 0 << ' ';
			s.push(_n);
		}
	}
}