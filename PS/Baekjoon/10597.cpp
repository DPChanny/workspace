#include<iostream>
#include<stack>

using namespace std;

string ns;
bool nus[100];
stack<int> p;

bool gs(int _n) {
	if(_n == ns.size()) {
		int _nu(1);
		while(_nu != 100 && nus[_nu++]);
		while(_nu != 100 && !nus[_nu++]);
		return _nu == 100;
	}
	if(!nus[ns[_n] - '0']) {
		nus[ns[_n] - '0'] = true;
		if(gs(_n + 1)) {
			p.push(ns[_n] - '0');
			return true;
		}
		nus[ns[_n] - '0'] = false;
	}
	if(_n + 1 != ns.size() && !nus[(ns[_n] - '0') * 10 + ns[_n + 1] - '0']) {
		nus[(ns[_n] - '0') * 10 + ns[_n + 1] - '0'] = true;
		if(gs(_n + 2)) {
			p.push((ns[_n] - '0') * 10 + ns[_n + 1] - '0');
			return true;
		}
		nus[(ns[_n] - '0') * 10 + ns[_n + 1] - '0'] = false;
	}
	return false;
}

int main(void) {
	cin >> ns;
	gs(0);
	while(!p.empty()) {
		cout << p.top() << ' '; p.pop();
	}
}