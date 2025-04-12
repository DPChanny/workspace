#include<iostream>
#include<set>

using namespace std;

typedef long long int lli;

lli n, c;
string b;
set<string> ns;

int main(void) {
	cin >> n;
	for (lli _n(0); _n < n; _n++) {
		cin >> b;
		if (!b.compare("ENTER"))	ns.clear();
		else if (ns.find(b) == ns.end()) {
			ns.insert(b);
			c++;
		}
	}
	cout << c;
}