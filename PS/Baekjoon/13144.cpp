#include<iostream>

using namespace std;

int n, ns[100'000], l, r;
bool nus[100'000];
long long int c;
int main(void) {
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	while(r < n) {
		if(nus[ns[r]]) nus[ns[l++]] = false;
		else {
			c += r - l + 1;
			nus[ns[r++]] = true;
		}
	}
	cout << c;
}