#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(void) {
	stack<int> s;
	int n;
	cin >> n;

	string p;

	vector<int> ns(n);
	vector<int> nns;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];

	int i(0);
	int pi(1);
	while (pi != n + 1){
		if (!s.empty() && s.top() == ns[i]) {
			nns.push_back(s.top());
			s.pop();
			p += "-\n";
			i++;
		}
		else {
			s.push(pi++);
			p += "+\n";
		}
	}

	while (!s.empty()) {
		nns.push_back(s.top());
		s.pop();
		p += "-\n";
	}

	if (equal(ns.begin(), ns.end(), nns.begin()))
		cout << p;
	else
		cout << "NO";
}