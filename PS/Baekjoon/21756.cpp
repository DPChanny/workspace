#include<iostream>

using namespace std;

int n, i;

int main(void) {
	cin >> n;
	while (1 << i < n + 1) i++;
	cout << (1 << i - 1);
}