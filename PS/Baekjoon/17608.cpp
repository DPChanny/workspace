#include<stack>
#include<iostream>

typedef long long int lli;

using namespace std;

lli n, b;
stack<lli> ns;

int main(void) {
	cin >> n;
	for (lli _n(0LL); _n < n; _n++) {
		cin >> b;
		while (!ns.empty() && ns.top() < b + 1LL) ns.pop();
		ns.push(b);
	}
	cout << ns.size();
}