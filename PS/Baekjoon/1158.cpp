#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	vector<int> ns(n);
	for (int _n(0); _n < n; _n++)
		ns[_n] = _n + 1;

	cout << '<';
	int ci(k - 1);
	for (int _n(0); _n < n - 1; _n++)
	{
		cout << ns[ci] << ", ";
		ns.erase(ns.begin() + ci);

		ci += k - 1;
		if (ci > ns.size() - 1)
			ci = ci % ns.size();
	}
	cout << ns[ci] << '>';
}