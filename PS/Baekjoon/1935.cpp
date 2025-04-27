#include<iostream>
#include<stack>
#include<map>

using namespace std;

int main(void) {
	stack<double> s;

	int n,
		ns[27];
	cin >> n;
	string c;
	cin >> c;

	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];

	for(int _i(0); _i < c.size(); _i++) {
		if(c[_i] == '*') {
			double a(s.top());
			s.pop();
			double b(s.top());
			s.pop();
			s.push(b * a);
		} else if(c[_i] == '/') {
			double a(s.top());
			s.pop();
			double b(s.top());
			s.pop();
			s.push(b / a);
		} else if(c[_i] == '+') {
			double a(s.top());
			s.pop();
			double b(s.top());
			s.pop();
			s.push(b + a);
		} else if(c[_i] == '-') {
			double a(s.top());
			s.pop();
			double b(s.top());
			s.pop();
			s.push(b - a);
		} else {
			s.push(ns[c[_i] - 'A']);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}
