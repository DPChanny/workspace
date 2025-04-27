#include<iostream>

using namespace std;

uint16_t by, bx;

int main(void) {
	cin >> by >> bx;
	if(bx < by) swap(bx, by);
	cout << (by - 1) + ((by) * (bx - 1));
}