#include<iostream>
#include<list>

using namespace std;

int n, ns[1'000];
list<int> rns;

int main(void) {
	cin >> n;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for (int _n(0); _n < n; _n++) {
		list<int>::iterator m(rns.begin());
		while(m != rns.end() && ns[_n] > *m) m++;
		rns.insert(m, ns[_n]);
	}
	for (list<int>::iterator _m(rns.begin()); _m != rns.end(); _m++)
		cout << *_m << '\n';
}