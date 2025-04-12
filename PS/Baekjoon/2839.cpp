#include<iostream>

using namespace std;

int n, c;

int main(void) {
	cin >> n;
	while(n > 0) {
		c += n % 5 ? 1 : n / 5;
		n -= n % 5 ? 3 : n;
	}
	cout << (n < 0 ? -1 : c);
}