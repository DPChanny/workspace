#include<iostream>

using namespace std;

int main(void) {
	int a, b, v;
	cin >> a >> b >> v;
	int g = a - b;
	cout << (v - a) / g + (((v - a) % g) ? 1 : 0) + 1;
}