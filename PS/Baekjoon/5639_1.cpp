#include<iostream>

using namespace std;

int n, po[10'000];

void mt(int* _po, const long long int& _s) {
	if (!_s) return;
	int* m(_po + 1);
	while (m - _po < _s && *m < *_po) m++;
	mt(_po + 1, m - _po - 1);
	mt(m, _s - (m - _po));
	cout << *_po << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while (!cin.eof())
		cin >> po[n++];
	n--;
	mt(po, n);
}