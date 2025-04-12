#include<iostream>

using namespace std;

unsigned long long int ns[91]{ 0,1, };
int n;

int main(void) {
	cin >> n;
	for(int _n(2); _n < n + 1; _n++)
		ns[_n] = ns[_n - 1] + ns[_n - 2];
	cout << ns[n];
}