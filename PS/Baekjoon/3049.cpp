#include<iostream>

using namespace std;

int n;

int main(void) {
	cin >> n;
	cout << n * (n - 1) * (n - 2) * (n - 3) / 24;
}