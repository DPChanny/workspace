#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k, c;
char ns[20'000];

int main(void) {
	cin >> n >> k; getchar();
	for (int _n(0); _n < n; _n++)
		ns[_n] = getchar();
	for (int _n(0); _n < n; _n++)
		if (ns[_n] == 'P')
			for (int _i(max(0, _n - k)); _i < _n + k + 1; _i++)
				if (ns[_i] == 'H') {
					ns[_i] = ' ';
					c++;
					break;
				}
	cout << c;
}