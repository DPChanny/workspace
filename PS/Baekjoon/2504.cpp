#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void) {
	stack<char> s;
	string n;
	cin >> n;
	int t(1);
	int r(0);
	for (int _n(0); _n < n.length(); _n++)
	{
		if (n[_n] == '(') {
			t *= 2;
			s.push(n[_n]);
		}
		else if (n[_n] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			s.pop();
			if (n[_n - 1] == '(') r += t;
			t /= 2;
		}
		else if (n[_n] == '[') {
			t *= 3;
			s.push(n[_n]);
		}
		else if (n[_n] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			s.pop();
			if (n[_n - 1] == '[') r += t;
			t /= 3;
		}
	}
	if (s.empty()) cout << r;
	else cout << 0;
}