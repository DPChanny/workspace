#include<iostream>
#include<stack>

using namespace std;

int n, ns[1'000'000];
stack<int> s, ps;

int main(void) {
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for(int _n(n - 1); _n + 1 > 0; _n--) {
		while(!s.empty() && s.top() < ns[_n] + 1) s.pop();
		if(s.empty()) ps.push(-1);
		else ps.push(s.top());
		s.push(ns[_n]);
	}
	while(!ps.empty()) {
		cout << ps.top() << ' ';
		ps.pop();
	}
}