#include<iostream>
#include<stack>

using namespace std;

string s, r;
stack<char> so;

int main(void) {
	cin >> s;
	for(int _s(0); _s < s.size(); _s++) {
		if(s[_s] == '(') so.push(s[_s]);
		else if(s[_s] == ')') {
			while(so.top() != '(') {
				r += so.top();  so.pop();
			}
			so.pop();
		}
		else if(s[_s] == '+' || s[_s] == '-') {
			while(!so.empty() && so.top() != '(') {
				r += so.top();  so.pop();
			}
			so.push(s[_s]);
		} else if(s[_s] == '*' || s[_s] == '/') {
			while(!so.empty() && so.top() != '(' && (so.top() == '*' || so.top() == '/')) {
				r += so.top();  so.pop();
			}
			so.push(s[_s]);
		} else r += s[_s];
	}
	while(!so.empty()) {
		r += so.top();  so.pop();
	}
	cout << r;
}
