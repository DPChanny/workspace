#include<iostream>

using namespace std;

int quadrant[3][3] = { {3, 0, 4}, {0, 0 ,0},{2, 0, 1} }, x, y;

int main(void) {
	cin >> x >> y;
	cout << quadrant[y / abs(y) + 1][x / abs(x) + 1];
}