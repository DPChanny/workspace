#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, c;
bool m[25][25]{ false, };
vector<int> fs;

bool check(int _y, int _x) {
	return
		_y + 1 > 0 && _y < n&&
		_x + 1 > 0 && _x < n&&
		m[_y][_x];
}

void fill(int _y, int _x) {
	if (check(_y, _x)) {
		c++;
		m[_y][_x] = false;
		fill(_y + 1, _x);
		fill(_y - 1, _x);
		fill(_y, _x + 1);
		fill(_y, _x - 1);
	}
}

int main(void) {
	cin >> n;
	for (int _y(0); _y < n; _y++) {
		getchar();
		for (int _x(0); _x < n; _x++)
			m[_y][_x] = getchar() - '0';
	}
	for (int _y(0); _y < n; _y++) {
		for (int _x(0); _x < n; _x++) {
			if (m[_y][_x]) {
				c = 0;
				fill(_y, _x);
				fs.push_back(c);
			}
		}
	}
	cout << fs.size() << '\n';
	sort(fs.begin(), fs.end());
	for (int _fs(0); _fs < fs.size(); _fs++)
		cout << fs[_fs] << '\n';
}