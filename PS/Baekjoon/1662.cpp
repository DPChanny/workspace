#include<iostream>
#include<string>
#include<stack>

using namespace std;

int c, t, n;
string i;
stack<int> s;

int main(void) {
	cin >> i;
	i += '0';
	for(int _i(0); _i < i.size() - 1; _i++) {
		if(i[_i] == ')') {
			t = 0;
			while(s.top() != -1) {
				t += s.top(); s.pop();
			}
			s.pop();
			n = s.top(); s.pop();
			s.push(n * t);
		} else if(i[_i] == '(') {
			s.push(-1);
		} else {
			if(i[_i + 1] != '(') s.push(1);
			else s.push(i[_i] - '0');
		}
	}
	while(!s.empty()) {
		c += s.top(); s.pop();
	}
	cout << c;
}