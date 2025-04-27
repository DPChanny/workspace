#include<iostream>

using namespace std;

unsigned int n;

int rs[8]{ 2, 1, 2 ,3, 4, 5, 4, 3 };

int main(void) {
	cin >> n;
	cout << rs[n % 8];
}