#include<iostream>

using namespace std;

constexpr int QTSC = 4;

int n;
bool ns[64][64];

pair<bool, string> gqts(int _n, int _y, int _x) {
	if(_n == 1) return { true, (ns[_y][_x] ? "1" : "0") };
	pair<bool, string> qtss[QTSC]{
		gqts(_n / 2, _y, _x),
		gqts(_n / 2, _y, _x + _n / 2),
		gqts(_n / 2, _y + _n / 2, _x),
		gqts(_n / 2, _y + _n / 2, _x + _n / 2)
	};
	string r, l(qtss[0].second);
	bool f(true);
	for(int _qts(0); _qts < QTSC; _qts++) {
		f = f && qtss[_qts].first;
		if(qtss[_qts].first) {
			if(f) {
				f = (l == qtss[_qts].second);
				l = qtss[_qts].second;
			}
			r += qtss[_qts].second;
		} else r += "(" + qtss[_qts].second + ")";
	}
	return { f, (f ? qtss[0].second : r) };
}

int main(void) {
	cin >> n;
	for(int _y(0); _y < n; _y++) {
		getchar();
		for(int _x(0); _x < n; _x++)
			ns[_y][_x] = getchar() - '0';
	}
	pair<bool, string> r = gqts(n, 0, 0);
	cout << (r.first ? r.second : "(" + r.second + ")");
}
