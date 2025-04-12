#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class D
{
public:
	int n;
	int x;
	bool f;

	D(int _n, int _x, bool _f) : n(_n), x(_x), f(_f) {

	}

	bool operator<(const D& _d) {
		return this->x < _d.x;
	}
};

int main(void) {
	int n, x, r;
	cin >> n;
	vector<D> ns;
	for (int _n(0); _n < n; _n++)
	{
		cin >> x >> r;
		ns.push_back(D(_n, x - r, true));
		ns.push_back(D(_n, x + r, false));
	}
	sort(ns.begin(), ns.end());
	stack<int> s;
	int lx(-2147483647 - 1);
	for (int _n(0); _n < n * 2; _n++)
	{
		if (lx == ns[_n].x) {
			cout << "NO";
			return 0;
		}

		if (ns[_n].f) {
			s.push(ns[_n].n);
		}
		else {
			if (s.top() != ns[_n].n) {
				cout << "NO";
				return 0;
			}
			s.pop();
		}
		lx = ns[_n].x;
	}

	if (s.empty()) cout << "YES";
	else cout << "NO";
}