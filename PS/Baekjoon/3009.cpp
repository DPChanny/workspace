#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, int> xc, yc;
vector<int> x, y;

int bx, by;

int main(void) {
	for(int i(0); i < 3; i++) {
		cin >> by >> bx;
		x.push_back(bx);
		y.push_back(by);
		xc[bx]++;
		yc[by]++;
	}
	for(int _y(0); _y < y.size(); _y++)
		if(yc[y[_y]] == 1) cout << y[_y] << ' ';
	for(int _x(0); _x < x.size(); _x++)
		if(xc[x[_x]] == 1) cout << x[_x];
}