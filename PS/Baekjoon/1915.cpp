#include<iostream>

using namespace std;

int y, x, yx[1001][1001], m;

int main(void) {
	cin >> y >> x;
	for(int _y(1); _y < y + 1; _y++) {
		getchar();
		for(int _x(1); _x < x + 1; _x++) {
			if(getchar() - '0') 
				yx[_y][_x] = min(min(yx[_y - 1][_x], yx[_y][_x - 1]), yx[_y - 1][_x - 1]) + 1;
			m = max(m, yx[_y][_x]);
		}
	}
	cout << m * m;
}